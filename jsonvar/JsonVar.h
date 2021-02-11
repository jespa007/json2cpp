/*
 *  This file is distributed under the MIT License.
 *  See LICENSE file for details.
 */


#pragma once




#if  !defined(MIN)
#define  MIN(a,  b)              ((a)  <  (b)  ?  (a)  :  (b))
#endif

#define ZJ_MAX_CONST_CHAR 50

#define ZJ_CONST_CHAR(s)\
	getChr(s,0),\
	getChr(s,1),\
	getChr(s,2),\
	getChr(s,3),\
	getChr(s,4),\
	getChr(s,5),\
	getChr(s,6),\
	getChr(s,7),\
	getChr(s,8),\
	getChr(s,9),\
	getChr(s,10),\
	getChr(s,11),\
	getChr(s,12),\
	getChr(s,13),\
	getChr(s,14),\
	getChr(s,15),\
	getChr(s,16),\
	getChr(s,17),\
	getChr(s,18),\
	getChr(s,19),\
	getChr(s,20),\
	getChr(s,21),\
	getChr(s,22),\
	getChr(s,23),\
	getChr(s,24),\
	getChr(s,25),\
	getChr(s,26),\
	getChr(s,27),\
	getChr(s,28),\
	getChr(s,29),\
	getChr(s,30),\
	getChr(s,31),\
	getChr(s,32),\
	getChr(s,33),\
	getChr(s,34),\
	getChr(s,35),\
	getChr(s,36),\
	getChr(s,37),\
	getChr(s,38),\
	getChr(s,39),\
	getChr(s,40),\
	getChr(s,41),\
	getChr(s,42),\
	getChr(s,43),\
	getChr(s,44),\
	getChr(s,45),\
	getChr(s,46),\
	getChr(s,47),\
	getChr(s,48),\
	getChr(s,49),\
	getChr(s,50)

#define getChr(name, ii) ((MIN(ii,ZJ_MAX_CONST_CHAR))<sizeof(name)/sizeof(*name)?name[ii]:0)

#define ZJ_CAST_JSON_VAR_STRING 				(zetjsoncpp::JsonVarString<> *)
#define ZJ_CAST_JSON_VAR_BOOLEAN 				(zetjsoncpp::JsonVarBoolean<> *)
#define ZJ_CAST_JSON_VAR_NUMBER 				(zetjsoncpp::JsonVarNumber<> *)
#define ZJ_CAST_JSON_VAR_OBJECT 				(zetjsoncpp::JsonVarObject<> *)
#define ZJ_CAST_JSON_VAR_VECTOR_OF_BOOLEANS 	(zetjsoncpp::JsonVarVectorBoolean<> *)
#define ZJ_CAST_JSON_VAR_VECTOR_OF_NUMBERS 		(zetjsoncpp::JsonVarVectorNumber<> *)
#define ZJ_CAST_JSON_VAR_VECTOR_OF_STRINGS 		(zetjsoncpp::JsonVarVectorString<> *)
#define ZJ_CAST_JSON_VAR_VECTOR_OF_OBJECTS 		(zetjsoncpp::JsonVarVectorObject<> *)
#define ZJ_CAST_JSON_VAR_MAP_OF_BOOLEANS 		(zetjsoncpp::JsonVarMapBoolean<> *)
#define ZJ_CAST_JSON_VAR_MAP_OF_NUMBERS 		(zetjsoncpp::JsonVarMapNumber<> *)
#define ZJ_CAST_JSON_VAR_MAP_OF_STRINGS 		(zetjsoncpp::JsonVarMapString<> *)
#define ZJ_CAST_JSON_VAR_MAP_OF_OBJECTS 		(zetjsoncpp::JsonVarMapObject<> *)

#define ZJ_FORMAT_OUTPUT_IDENT(str_value,ident)  for (int k = 0; k <= (ident + 1); k++) str_value += "\t";
#define ZJ_FORMAT_OUTPUT_NEW_LINE(str_value,ident) \
	str_value += "\n";\
	for (int k = 0; k <= (ident + 1); k++)	str_value += "\t";

#define ZJ_PROPERTY_OUTPUT_FORMAT_MINIMIZED 	(0x1 << 0)

namespace zetjsoncpp {

	typedef enum:uint16_t{
		JSON_VAR_TYPE_UNKNOWN		 =0, // 0
		JSON_VAR_TYPE_BOOLEAN		 =0x1<<1, // 0x01
		JSON_VAR_TYPE_NUMBER		 =0x1<<2, // 0x02
		JSON_VAR_TYPE_STRING		 =0x1<<3, // 0x03
		JSON_VAR_TYPE_OBJECT		 =0x1<<4, // 0x04
		JSON_VAR_TYPE_VECTOR 		= 0x100,  //
		JSON_VAR_TYPE_VECTOR_OF_BOOLEANS = JSON_VAR_TYPE_VECTOR+JSON_VAR_TYPE_BOOLEAN, // 6
		JSON_VAR_TYPE_VECTOR_OF_NUMBERS = JSON_VAR_TYPE_VECTOR+JSON_VAR_TYPE_NUMBER, // 7
		JSON_VAR_TYPE_VECTOR_OF_STRINGS =JSON_VAR_TYPE_VECTOR+JSON_VAR_TYPE_STRING, // 9
		JSON_VAR_TYPE_VECTOR_OF_OBJECTS = JSON_VAR_TYPE_VECTOR+JSON_VAR_TYPE_OBJECT, //10
		JSON_VAR_TYPE_MAP=0x200,
		JSON_VAR_TYPE_MAP_OF_BOOLEANS = JSON_VAR_TYPE_MAP+JSON_VAR_TYPE_BOOLEAN, // 12
		JSON_VAR_TYPE_MAP_OF_NUMBERS = JSON_VAR_TYPE_MAP+JSON_VAR_TYPE_NUMBER, // 13
		JSON_VAR_TYPE_MAP_OF_STRINGS = JSON_VAR_TYPE_MAP+JSON_VAR_TYPE_STRING, // 14
		JSON_VAR_TYPE_MAP_OF_OBJECTS = JSON_VAR_TYPE_MAP+JSON_VAR_TYPE_OBJECT, // 15

	}JsonVarType;

	class JsonVar {//: public CVariable {
	public:

		static const char *idTypeToString(int index);

		static char const STR_EMPTY[];

		JsonVar();

		virtual JsonVar *newData();
		virtual JsonVar *newData(const std::string & key);

		const char *toTypeStr();

		virtual std::string toString();
		virtual std::string toStringFormatted(int ident, uint16_t properties);

		virtual ~JsonVar();

		void * getPtrData(){ return __js_ptr_data__;}
		void * getPtrDataEnd(){return __js_ptr_data_end__;}
		size_t  getSizeData(){return __js_size_data__;}
		JsonVarType getType(){return __js_type__;}
		std::string getVariableName(){return __js_variable_name__;}

		void setParsed(bool parsed);

		bool isParsed() const;

	protected:
		bool __js_is_parsed__;
		JsonVarType __js_type__;
		size_t __js_size_data__;
		std::string  __js_variable_name__;
		void 	     *__js_ptr_data__; // can be int, bool, vector, prop_grp, etc ...
		JsonVar *__js_ptr_data_end__;
	};



};

#include "JsonVarNamed.h"
#include "JsonVarBoolean.h"
#include "JsonVarNumber.h"
#include "JsonVarString.h"
#include "JsonVarObject.h"
#include "JsonVarVector.h"
#include "JsonVarVectorBoolean.h"
#include "JsonVarVectorNumber.h"
#include "JsonVarVectorString.h"
#include "JsonVarVectorObject.h"
#include "JsonVarMap.h"
#include "JsonVarMapBoolean.h"
#include "JsonVarMapNumber.h"
#include "JsonVarMapString.h"
#include "JsonVarMapObject.h"


