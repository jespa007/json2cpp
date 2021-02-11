namespace zetjsoncpp{

	template<char... _T_NAME>
	class JsonVarMapBoolean: public JsonVarNamed<_T_NAME...>, public JsonVarMap<bool> {

	public:

		JsonVarMapBoolean() {
			this->__js_type__ = JsonVarType::JSON_VAR_TYPE_MAP_OF_BOOLEANS;
			this->__js_size_data__ = sizeof(JsonVarMapBoolean< _T_NAME...>);
			this->__js_ptr_data__ = &this->__js_map_data__;
		}

		//std::string result_json;
		virtual std::string toStringFormatted(int ident, uint16_t properties) {

			bool not_minimized = ((properties & ZJ_PROPERTY_OUTPUT_FORMAT_MINIMIZED) == 0);
			std::string str_value = this->toStringFormattedStart(ident, properties);

			int j=0;
			for (auto it=__js_map_data__.begin();it !=__js_map_data__.end();it++,j++) {

				if (j > 0){
					str_value += ",";
				}

				str_value += "\""+it->first +"\":"+ (it->second==true?"true":"false")+"";// this->str_value + "\"" + v->at(j) + "\" ";

				if (not_minimized){
					ZJ_FORMAT_OUTPUT_NEW_LINE(str_value,ident);
				}
			}

			str_value += this->toStringFormattedEnd(ident,properties);

			return str_value;

		}

		void destroy() {

		}

		virtual ~JsonVarMapBoolean() {
			destroy();
		}
	};
}
