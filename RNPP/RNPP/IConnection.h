#pragma once

class IConnectable;
class IConverter;

class IConnection
{
    public:
        typedef unsigned long long id_t;

        virtual bool IsConnected() const = 0;
        virtual IConnectable* From() const = 0;
        virtual IConnectable* To() const = 0;

        virtual IConverter* GetConverter() const = 0;
};

