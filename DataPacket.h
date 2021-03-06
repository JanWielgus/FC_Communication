/**
 * @file DataPacket.h
 * @author Jan Wielgus
 * @brief Concrete class that implement IDataPacket interface.
 * Can be used to create data packets instances.
 * @date 2020-08-05
 * 
 */

#ifndef DATAPACKET_H
#define DATAPACKET_H

#include "IDataPacket.h"
#include <IArray.h>


class DataPacket : public IDataPacket
{
private:
    const uint8_t PacketID;
    IArray<uint8_t*>* bytePointersArray = nullptr;
    bool useExternalArray = false; // true if used parametrized constructor (do not delete in destructor)
    IExecutable* packetReceivedEvent = nullptr;


public:
    DataPacket(uint8_t packetID);
    /**
     * @param packetID ID of the packet.
     * @param arrayPointer Pointer to external instance of IArray type.
     * Don't forget to delete manually if this array is dynamically allocated.
     */
    DataPacket(uint8_t packetID, IArray<uint8_t*>* arrayPointer);
    virtual ~DataPacket();

    DataPacket(const DataPacket& other) = delete;
    DataPacket& operator=(const DataPacket& other) = delete;

    void addByteType(IByteType& toAdd) override;
    uint8_t getPacketID() const override;
    size_t getPacketSize() const override;
    uint8_t** getBytePointersArray() override;
    const uint8_t** getBytePointersArray() const override;
    void setPacketReceivedEvent(IExecutable& packetReceivedEvent) override;
    IExecutable* getPacketReceivedEventPtr() const override;
};


#endif
