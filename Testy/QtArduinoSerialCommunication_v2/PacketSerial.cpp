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
    while (arduinoSerial->bytesAvailable() > 0)
    {
        QByteArray dataRead;
        dataRead.resize(MAX_SEND_SIZE);

        dataRead = arduinoSerial->read(MAX_SEND_SIZE);

        for (unsigned int q=0; q < MAX_SEND_SIZE; q++)
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
    //if (buffer == 0 || size == 0) return;

    uint8_t _encodeBuffer[COBS::getEncodedBufferSize(size)];

    size_t numEncoded = COBS::encode(buffer,
                                     size,
                                     _encodeBuffer);
    arduinoSerial->write((char*)_encodeBuffer, numEncoded);
    arduinoSerial->write((char*)PacketMarker); // Jeżeli błąd to dodać (char*)  !!!
}



void PacketSerial::setPacketHandler(PacketHandlerFunction onPacketFunction)
{
    _onPacketFunction = onPacketFunction;
}
