/*

Class for sending various http responses

*/

#ifndef response_hpp
#define response_hpp

#include <string>
#include <iostream>
#include <fstream>
#include <iterator>

namespace network
{
    class HTTPResponse
    {
    private:
        // header variables needed to send a http response
        int status_code;              // [ 200 | 300 | 500 ]
        std::string status_message;   // [ OK ]
        std::string protocol;         // HTTP/1.1
        std::string content_type;     // [ text/html | application/pdf ]
        int content_length;           // length of content
        std::string server;           // server name
        std::string date;             // date no types available in C++
        std::string last_modified;    // last modified date on server
        std::string accept_ranges;    // a unit of resp, [ bytes | none ]
        std::string X_Frame_Options;  // whether the site allows iframes and frames [ SAMEORIGIN | DENY | ALLOW-FROM uri ]
        std::string content_encoding; // Specifies the encoding applied to payload [ gzip | compress | deflate | br ]
        std::string connection;       // connection after current transaction is over [ keep-alive | close ]
        std::string response;

    public:
        // constructor

        HTTPResponse(
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
            std::string _connection
        );

        std::string SendHTMLFileAsResponse(std::string filename);

        std::string SentTextResponse(std::string text);

        std::string make_http_response();

        template <typename T, typename... Args>
        std::string merger(T t, Args... args);

        std::string merger();

        std::string to_string(std::string);

        std::string to_string(int);

        // getters
        std::string get_response();
        int get_status_code();
        // setters
        void set_response(std::string resp);
        void set_status_code(int s_code);
    };
}

#endif
