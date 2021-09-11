#include "response.hpp"

network::HTTPResponse::HTTPResponse(
    int _status_code,
    std::string _status_message,
    std::string _protocol,
    std::string _content_type,
    std::string _server,
    std::string _date,
    std::string _last_modified,
    std::string _accept_ranges,
    std::string _X_Frame_Options,
    std::string _content_encoding)
{
    status_code = _status_code;
    status_message = _status_message;
    protocol = _protocol;
    content_type = _content_type;
    server = _server;
    date = _date;
    last_modified = _last_modified;
    accept_ranges = _accept_ranges;
    X_Frame_Options = _X_Frame_Options;
    content_encoding = _content_encoding;
}

char *network::HTTPResponse::SendHTMLFileAsResponse(std::string filename)
{
}

char *network::HTTPResponse::SentTextResponse(std::string text)
{
    content_length = (int)text.length();
    response = text;
    return make_http_request();
}

char *network::HTTPResponse::make_http_request()
{
    std::string resp = "";
    resp += merger(protocol,status_code,status_message);
    std::cout<<resp<<"\n";
}



std::string network::HTTPResponse::merger()
{
    return "\r\n";
}

std::string network::HTTPResponse::to_string(int x)
{
    return std::to_string(x);
}

std::string network::HTTPResponse::to_string(std::string s)
{
    return s;
}


template<typename T,typename... Args>
std::string network::HTTPResponse::merger(T t, Args... args)
{
    return to_string(t) + " " + merger(args...);
}