#pragma once

RNPP_NAMESPACE_BEGIN()

class INode;
class IDataType;
class Context;

class IConnectable
{
    const INode* m_node = nullptr;
    Context* m_context = nullptr;

public:
    typedef unsigned long long id_t;

    virtual const id_t GetId() const = 0;
    virtual const IDataType* GetType() const = 0;
    virtual bool IsConnected() const = 0;


    const INode* GetNode() const;
    const Context * GetContext() const; 

#if defined(RNPP_INTERNAL)
    static void SetNode(IConnectable* instance, INode* node);
    static void SetContext(IConnectable* instance, Context* context);
#endif
};

RNPP_NAMESPACE_END()

