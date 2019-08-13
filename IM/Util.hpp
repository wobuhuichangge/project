#pragma once

#include<iostream>
#include<string>
#include<json/json.h>
#include<memory>
#include"mongoose.h"

using namespace std;
class Util
{
    public:
        string mgStrToString(struct mg_str *ms)
        {
            string ret = "";
            int len = ms->len;
            for(auto i = 0;i<len;i++)
            {
                ret.push_back(ms->p[i]);
            }

            return ret;
        }

        static bool GetNameAndPasswd(string info,string &name,string&passwd)
        {
            //{name:"zhangsan",passwd:"12345"}
            bool result;
            //fan xu lie hua
            JSONCPP_STRING errs;
            Json::Value root;
            Json::CharReaderBuilder cb;
            std::unique_ptr<Json::CharReader> const cr(cb.newCharReader());
            result = cr->parse(info.data(),info.data()+info.size(),&root,&errs);
            if(!result || !errs.empty())
            {
                cerr<<"parse error"<<endl;
                return false;
            }

            name = root["name"].asString();
            passwd = root["passwd"].asString();
            return true;

        }
};
