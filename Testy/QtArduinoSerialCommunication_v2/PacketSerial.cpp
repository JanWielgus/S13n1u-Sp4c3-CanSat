#include "PacketSerial.h"

PacketSerial::PacketSerial()
{
    _recieveBuffer = new uint8_t[BufferSize];
}



void PacketSerial::setArduinoSerial(QSerialPort *sserial)
{
    arduinoSerial = sserial;
}



void PacketSerial::update()
{
    int bytes_waiting;
    while ((bytes_waiting = arduinoSerial->bytesAvailable()) > 0)
    {
        QByteArray dataRead;
        dataRead.resize(MAX_SEND_SIZE);

        dataRead = arduinoSerial->read(MAX_SEND_SIZE);

        int maxNum = (bytes_waiting<=MAX_SEND_SIZE?bytes_waiting:MAX_SEND_SIZE);
        for (int q=0; q < maxNum; q++)
        {
            uint8_t dataByte = dataRead[q];

            if (dataByte == PacketMarker)
            {
                if (_onPacketFunction)
                {
                    uint8_t _decodeBuffer[_recieveBufferIndex];

                    size_t numDecoded = COBS::decode(_recieveBuffer,
                                                     _recieveBufferIndex,
                                                     _decodeBuffer);
                    _onPacketFunction(_decodeBuffer, numDecoded);
                }

                _recieveBufferIndex = 0;
            }
            else
            {
                if ((_recieveBufferIndex + 1) < BufferSize)
                {
                    _recieveBuffer[_recieveBufferIndex++] = dataByte;
                }
                else
                {
                    // Error, buffer overflow if we write.
                }
            }
        }
    }
}



void PacketSerial::send(const uint8_t *buffer, size_t size)
{
    if (buffer == 0 || size == 0) return;

    uint8_t _encodeBuffer[COBS::getEncodedBufferSize(size)];

    size_t numEncoded = COBS::encode(buffer, size, _encodeBuffer);

    char* _encBuf = reinterpret_cast<char*>(_encodeBuffer); // rzutowanie uint8_t* na char*
    char* PacMak = reinterpret_cast<char*>(PacketMarker);

    arduinoSerial->write(_encBuf, numEncoded);
    //arduinoSerial->waitForBytesWritten();
    arduinoSerial->write(PacMak);
}



void PacketSerial::setPacketHandler(PacketHandlerFunction onPacketFunction)
{
    _onPacketFunction = onPacketFunction;
}
