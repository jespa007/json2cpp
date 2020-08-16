/*
 *  This file is distributed under the MIT License.
 *  See LICENSE file for details.
 */

#pragma once



namespace zetjsoncpp{

	class ParserBase{
	protected:

		std::string filename;
		std::string error;

	public:
	  ParserBase(){}

	 virtual ~ParserBase(){}
	};

};
