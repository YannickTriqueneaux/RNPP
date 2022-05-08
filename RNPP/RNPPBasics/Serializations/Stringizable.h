namespace TrustEngine{
    namespace Serialization{

        template<typename FORMAT>
        class Stringizable : public Element<FORMAT>{
        public:
            typedef Value<FORMAT>* ContentType;


            Stringizable(StringId const & objectname, int indentrange);
            ~Stringizable();

            virtual bool print(std::ostream & streamResult) const;

            ContentType value = nullptr;
        private:
            int indentRange = 0;
            StringId name;
        };
    };
};//TENS