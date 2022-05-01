#pragma once
class IVariable
{
public:
    typedef unsigned long long id_t;

    virtual bool HasChanged() const = 0;
};

