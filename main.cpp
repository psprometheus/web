#include <crow.h>
#include <string>
using namespace std;


int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        crow::response rep;
        rep.set_static_file_info("index.html");

        return rep;
    });
    CROW_ROUTE(app, "/souls")([](){
        crow::response rep;
        rep.set_static_file_info("souls.html");

        return rep;
    });
    CROW_ROUTE(app, "/<string>")([](string filename){
        crow::response rep;
        rep.set_static_file_info(filename);
        return rep;
    });

    app.port(80).multithreaded().run();
}