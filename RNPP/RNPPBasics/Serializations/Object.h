namespace TrustEngine{ namespace Serialization{

    template<typename FORMAT>
    class Object : public Element<FORMAT>{
    public:
        typedef std::unordered_map<StringId, Element<FORMAT> const *> ContentType;


        Object(StringId const & objectname, int indentrange);
        virtual ~Object();

        virtual bool print(std::ostream & streamResult) const ;

        ContentType members;
        int getIndent() const;
    private:
        int indentRange = 0;
        StringId name;
    };
};
RNPPBASICS_NAMESPACE_END()