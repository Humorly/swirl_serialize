#pragma once
#include "json.hpp"
#include "data_declaration.h"
namespace wstd {

	inline std::string serialize (student ____object_st) 
	{
		nlohmann::json json_data = {
			{ "age", ____object_st.age },
			{ "name", ____object_st.name },
			{ "gender", ____object_st.gender },
			{ "score", ____object_st.score },
		};
		return json_data.dump();
	}

	inline void deserialize (student& ____object_st, nlohmann::json ____object_json) 
	{
		____object_st.age = ____object_json["age"];

    		for (auto i = 0; i < ____object_json["name"].size(); i++)
    		{
    		    ____object_st.name[i] = ____object_json["name"][i];
    		}
		____object_st.gender = ____object_json["gender"];

    		for (auto i = 0; i < ____object_json["score"].size(); i++)
    		{
    		    for (auto j = 0; j < ____object_json["score"][i].size(); j++)
    		    {
    		        for (auto k = 0; k < ____object_json["score"][i][j].size(); k++)
    		        {
    		            ____object_st.score[i][j][k] = ____object_json["score"][i][j][k];
    		        }
    		    }
    		}
	};
}