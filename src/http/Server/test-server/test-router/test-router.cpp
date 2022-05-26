#include "test-router.hpp"

network::TestRouter::TestRouter() {}

// sends the final reponse as a string
std::string network::TestRouter::routeRequests(network::HTTPRequest *request, network::HTTPResponse *response)
{
    // write all cases here
    if (request->get_request_route() == "/")
    {
        response->set_status_code(200);
        response->set_status_message("OK");
        return response->SendFileAsResponse("../Frontend/html/index.html");
    };

    if (request->get_request_route() == "/stylesheets/index.css")
    {
        response->set_status_code(200);
        response->set_status_message("OK");
        response->set_content_type("text/css");
        return response->SendFileAsResponse("../Frontend/stylesheets/index.css");
    }

    // if (request->get_request_route() == "/favicon.ico")
    // {
    //     response->set_status_code(200);
    //     response->set_status_message("OK");
    //     response->set_content_type("image/gif");
    //     return response->SendFileAsResponse("../Frontend/images/favicon-32x32.png");
    // }

    response->set_status_code(400);
    response->set_status_message("BAD REQUEST");
    return response->SendTextResponse("Fuck You! You got the wrong route");
    
}