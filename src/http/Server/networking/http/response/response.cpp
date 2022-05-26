#include "response.hpp"

network::HTTPResponse::HTTPResponse() {}

std::string network::HTTPResponse::SendFileAsResponse(std::string filename)
{
    std::ifstream ifs(filename);
    std::string file_content(std::istreambuf_iterator<char>{ifs}, {});
    content_length = file_content.length();
    set_response(file_content);
    return make_http_response();
}

std::string network::HTTPResponse::SendTextResponse(std::string text)
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
    resp += merger(printObject("Date", response_time));
    resp += merger(printObject("Server", server_name));
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

std::string network::HTTPResponse::get_status_message()
{
    return status_message;
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

void network::HTTPResponse::set_status_message(std::string _s_message)
{
    status_message = _s_message;
}

void network::HTTPResponse::set_protocol(std::string _protocol)
{
    protocol = _protocol;
}

void network::HTTPResponse::set_content_type(std::string _content_type)
{
    content_type = _content_type;
}

void network::HTTPResponse::set_content_length(int _content_length)
{
    content_length = _content_length;
}

void network::HTTPResponse::set_server_name(std::string _server_name)
{
    server_name = _server_name;
}

void network::HTTPResponse::set_response_time(std::string _response_time)
{
    response_time = _response_time;
}

void network::HTTPResponse::set_last_modified(std::string _last_modified)
{
    last_modified = _last_modified;
}


void network::HTTPResponse::set_accept_ranges(std::string _accept_ranges)
{
    accept_ranges = _accept_ranges;
}

void network::HTTPResponse::set_X_Frame_Options(std::string _X_Frame_Options)
{
    X_Frame_Options = _X_Frame_Options;
}

void network::HTTPResponse::set_content_encoding(std::string _content_encoding)
{
    content_encoding = _content_encoding;
}

void network::HTTPResponse::set_connection(std::string _connection)
{
    connection = _connection;
}


