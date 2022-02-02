#include "noc_link.h"


// this represents a link in the NoC
NocLink::NocLink(NocRouterId source, NocRouterId sink):source_router(source), sink_router(sink)
{
    // initialize variables
    bandwidth_usage = 0.0;
    number_of_connections = 0;
    
}

NocLink::~NocLink()
{

}

// getters
NocRouterId NocLink::get_source_router(void) const{
    return source_router;
}

NocRouterId NocLink::get_sink_router(void) const{
    return sink_router;
}

double NocLink::get_bandwidth_usage(void) const{
    return bandwidth_usage;
}

int NocLink::get_number_of_connections(void) const{
    return number_of_connections;
}

//setters
void NocLink::set_bandwidth_usage(double new_bandwidth_usage)
{
    bandwidth_usage = new_bandwidth_usage;
}

void NocLink::set_number_of_connections(int new_number_of_connections)
{
    number_of_connections = new_number_of_connections;
}