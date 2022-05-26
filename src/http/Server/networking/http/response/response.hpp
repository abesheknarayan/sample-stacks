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
        int status_code;              // [ 200 | 400 | 401 | 404 | 500 ]
        std::string status_message;   // [ OK | Bad Request | Unauthorized | Not Found | Internal Server Error ]
        std::string protocol;         // HTTP/1.1
        std::string content_type;     // [ text/html | application/pdf ]
        int content_length;           // length of content
        std::string server_name;           // server name
        std::string response_time;             // date no types available in C++
        std::string last_modified;    // last modified date on server
        std::string accept_ranges;    // a unit of resp, [ bytes | none ]
        std::string X_Frame_Options;  // whether the site allows iframes and frames [ SAMEORIGIN | DENY | ALLOW-FROM uri ]
        std::string content_encoding; // Specifies the encoding applied to payload [ gzip | compress | deflate | br ]
        std::string connection;       // connection after current transaction is over [ keep-alive | close ]
        std::string response;

    public:
        // constructor

        HTTPResponse();

        std::string SendFileAsResponse(std::string filename);

        std::string SendTextResponse(std::string text);

        std::string make_http_response();

        template <typename T, typename... Args>
        std::string merger(T t, Args... args);

        std::string merger();

        std::string to_string(std::string);

        std::string to_string(int);

        // getters
        std::string get_response();
        int get_status_code(); 
        std::string get_status_message();


        // setters
        void set_response(std::string _response);
        void set_status_code(int _status_code);
        void set_status_message(std::string _status_message);
        void set_protocol(std::string _protocol);
        void set_content_type(std::string _content_type);   
        void set_content_length(int _content_length);          
        void set_server_name(std::string _server_name);       
        void set_response_time(std::string _response_time);    
        void set_last_modified(std::string _last_modified);    
        void set_accept_ranges(std::string _accept_ranges);   
        void set_X_Frame_Options(std::string _X_Frame_Options);  
        void set_content_encoding(std::string _content_encoding); 
        void set_connection(std::string _connection);       
    };
}

#endif
