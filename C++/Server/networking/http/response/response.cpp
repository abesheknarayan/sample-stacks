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
    std::string _content_encoding,
    std::string _connection)
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
    connection = _connection;
}

std::string network::HTTPResponse::SendHTMLFileAsResponse(std::string filename)
{
    std::ifstream ifs(filename);
    std::string file_content(std::istreambuf_iterator<char>{ifs}, {});
    content_length = file_content.length();
    set_response(file_content);
    return make_http_response();
}

std::string network::HTTPResponse::SentTextResponse(std::string text)
{
    content_length = (int)text.length();
    set_response(text);
    return make_http_response();
}

std::string printObject(std::string key, std::string val)
{
    return key + ": " + val;
}

std::string printObject(std::string key, int val)
{
    return key + ": " + std::to_string(val);
}

std::string network::HTTPResponse::make_http_response()
{
    std::string resp = "";
    resp += merger(protocol, status_code, status_message);
    resp += merger(printObject("Date", date));
    resp += merger(printObject("Server", server));
    resp += merger(printObject("Last-Modified", last_modified));
    resp += merger(printObject("Content-Type", content_type));
    resp += merger(printObject("Content-Length", content_length));
    resp += merger(printObject("Accept-Ranges", accept_ranges));
    resp += merger(printObject("Connection", connection));
    resp += "\n";
    resp += response;
    return resp.c_str();
}

std::string network::HTTPResponse::merger()
{
    return "\n";
}

std::string network::HTTPResponse::to_string(int x)
{
    return std::to_string(x);
}

std::string network::HTTPResponse::to_string(std::string s)
{
    return s;
}

template <typename T, typename... Args>
std::string network::HTTPResponse::merger(T t, Args... args)
{
    return to_string(t) + " " + merger(args...);
}

// getters

std::string network::HTTPResponse::get_response()
{
    return response;
}

int network::HTTPResponse::get_status_code()
{
    return status_code;
}

// setters

void network::HTTPResponse::set_response(std::string resp)
{
    response = resp;
}

void network::HTTPResponse::set_status_code(int s_code)
{
    status_code = s_code;
}
