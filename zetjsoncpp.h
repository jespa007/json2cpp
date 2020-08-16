/*
 *  This file is distributed under the MIT License.
 *  See LICENSE file for details.
 */

#pragma once
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <memory.h>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>
#include <locale>
#include <codecvt>
#include <sys/stat.h>
#include <sys/types.h>
#include <exception>
#include <stdexcept>
#include <float.h>
#include <limits.h>


#define ZETJSONCPP_MAJOR_VERSION 2
#define ZETJSONCPP_MINOR_VERSION 0
#define ZETJSONCPP_PATCH_VERSION 0

#ifdef __MEMMANAGER__
#include "memmgr.h"
#endif

#include "util/zj_strutils.h"
#include "util/zj_file.h"
#include "util/zj_path.h"




#include "exception.h"
#include "var/ParserVar.h"
#include "ParserBase.h"
#include "Parser.h"


// static zetjsoncpp

namespace zetjsoncpp {

	template <typename _T>
	class ZetJsonCpp : public Parser<_T> {

	public:

		ZetJsonCpp() {}

		virtual void eval(const std::string & expression) {

			this->line = 1;
			this->root_struct_field->destroy(); // destroy previous elements!

			eval((const char *)expression.c_str(), Parser<_T>::root_struct_field, 0);
		}

		virtual ~ZetJsonCpp() {}
	private:

		static bool isSingleComment(char *str);
		static bool isStartComment(char *str);
		static bool isEndComment(char *str);
		static char *advanceToChar(char *str,char c);
		static char *advanceToEndComment(char *aux_p, int &line);
		static char *ignoreBlanks(char *str, int &line);
		static char *advanceToOneOfCollectionOfChar(char *str,char *end_char_standard_value, int &line);

		ParserVar *findProperty(ParserVar * c_data, char *variable_name);
		void setPropertiesParsedToFalse(ParserVar * c_data);
		//void printJsonError(char *m_start_ptr, char *m_current_ptr, int column, const char *error_message);
		bool bothAreTypeNumbers(int type1, int type2);


		int eval(const char * start_str, ParserVar *c_data, int level = 0);


	};

};

#include "zetjsoncpp.inc"


