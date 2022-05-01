#pragma once
class IConnectable
{
public:
    typedef unsigned long long id_t;

    virtual bool IsConnected() const = 0;
};

