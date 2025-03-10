#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <climits>
#include <functional>
#include <iomanip>
#include <stack>
#include <set>
#include <cstring>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi " << __LINE__ << endl

#define SET(func_name,type,var_name,_var_name) void func_name(type _var_name) { var_name = _var_name ;} 
#define GET(func_name,type,var_name) type func_name() const { return var_name ;}

class header;
class payload;
class packet;
class node;
class event;
class link; // new

// for simplicity, we use a const int to simulate the delay
// if you want to simulate the more details, you should revise it to be a class
const unsigned int ONE_HOP_DELAY = 10;
const unsigned int BROADCAST_ID = UINT_MAX;

// BROADCAST_ID means that all neighbors are receivers; UINT_MAX is the maximum value of unsigned int

// MARK: Header
class header {
    public:
        virtual ~header() {}

        SET(setSrcID, unsigned int , srcID, _srcID);
        SET(setDstID, unsigned int , dstID, _dstID);
        SET(setPreID, unsigned int , preID, _preID);
        SET(setNexID, unsigned int , nexID, _nexID);
        GET(getSrcID, unsigned int , srcID);
        GET(getDstID, unsigned int , dstID);
        GET(getPreID, unsigned int , preID);
        GET(getNexID, unsigned int , nexID);
        
        virtual string type() = 0;
        
        // factory concept: generate a header
        class header_generator {
                // lock the copy constructor
                header_generator(header_generator &){}
                // store all possible types of header
                static map<string,header_generator*> prototypes;
            protected:
                // allow derived class to use it
                header_generator() {}
                // after you create a new header type, please register the factory of this header type by this function
                void register_header_type(header_generator *h) { prototypes[h->type()] = h; }
                // you have to implement your own generate() to generate your header
                virtual header* generate() = 0 ;
            public:
                // you have to implement your own type() to return your header type
                virtual string type() = 0 ;
        	    // this function is used to generate any type of header derived
        	    static header * generate (string type) {
            		if(prototypes.find(type) != prototypes.end()){ // if this type derived exists 
            			return prototypes[type]->generate(); // generate it!!
            		}
            		std::cerr << "no such header type" << std::endl; // otherwise
                    return nullptr;
                }
                static void print () {
                    cout << "registered header types: " << endl;
                    for (map<string,header::header_generator*>::iterator it = prototypes.begin(); it != prototypes.end(); it ++)
                        cout << it->second->type() << endl;
                }
                virtual ~header_generator(){};
        };
        
    protected:
        header():srcID(BROADCAST_ID),dstID(BROADCAST_ID),preID(BROADCAST_ID),nexID(BROADCAST_ID){} // this constructor cannot be directly called by users

    private:
        unsigned int srcID;
        unsigned int dstID;
        unsigned int preID;
        unsigned int nexID;
        header(header&){} // this constructor cannot be directly called by users
};
map<string,header::header_generator*> header::header_generator::prototypes;

class IoT_data_header : public header{
        IoT_data_header(IoT_data_header&){} // cannot be called by users
        
    protected:
        IoT_data_header(){} // this constructor cannot be directly called by users

    public:
        ~IoT_data_header(){}
        string type() { return "IoT_data_header"; }

        class IoT_data_header_generator;
        friend class IoT_data_header_generator;
        // IoT_data_header_generator is derived from header_generator to generate a header
        class IoT_data_header_generator : public header_generator{
                static IoT_data_header_generator sample;
                // this constructor is only for sample to register this header type
                IoT_data_header_generator() { /*cout << "IoT_data_header registered" << endl;*/ register_header_type(&sample); }
            protected:
                virtual header * generate(){
                    // cout << "IoT_data_header generated" << endl;
                    return new IoT_data_header; 
                }
            public:
                virtual string type() { return "IoT_data_header";}
                ~IoT_data_header_generator(){}
        
        };
};
IoT_data_header::IoT_data_header_generator IoT_data_header::IoT_data_header_generator::sample;

class IoT_ctrl_header : public header{
        IoT_ctrl_header(IoT_ctrl_header&){} // cannot be called by users
        
    protected:
        IoT_ctrl_header(){} // this constructor cannot be directly called by users

    public:
        ~IoT_ctrl_header(){}
        string type() { return "IoT_ctrl_header"; }

        class IoT_ctrl_header_generator;
        friend class IoT_ctrl_header_generator;
        // IoT_ctrl_header_generator is derived from header_generator to generate a header
        class IoT_ctrl_header_generator : public header_generator{
                static IoT_ctrl_header_generator sample;
                // this constructor is only for sample to register this header type
                IoT_ctrl_header_generator() { /*cout << "IoT_ctrl_header registered" << endl;*/ register_header_type(&sample); }
            protected:
                virtual header * generate(){
                    // cout << "IoT_ctrl_header generated" << endl;
                    return new IoT_ctrl_header; 
                }
            public:
                virtual string type() { return "IoT_ctrl_header";}
                ~IoT_ctrl_header_generator(){}
        
        };
};
IoT_ctrl_header::IoT_ctrl_header_generator IoT_ctrl_header::IoT_ctrl_header_generator::sample;


class AGG_ctrl_header : public header{
        AGG_ctrl_header(AGG_ctrl_header&){} // cannot be called by users
        
    protected:
        AGG_ctrl_header(){} // this constructor cannot be directly called by users

    public:
        ~AGG_ctrl_header(){}
        string type() { return "AGG_ctrl_header"; }

        class AGG_ctrl_header_generator;
        friend class AGG_ctrl_header_generator;
        // AGG_ctrl_header_generator is derived from header_generator to generate a header
        class AGG_ctrl_header_generator : public header_generator{
                static AGG_ctrl_header_generator sample;
                // this constructor is only for sample to register this header type
                AGG_ctrl_header_generator() { /*cout << "AGG_ctrl_header registered" << endl;*/ register_header_type(&sample); }
            protected:
                virtual header * generate(){
                    // cout << "AGG_ctrl_header generated" << endl;
                    return new AGG_ctrl_header; 
                }
            public:
                virtual string type() { return "AGG_ctrl_header";}
                ~AGG_ctrl_header_generator(){}
        
        };
};
AGG_ctrl_header::AGG_ctrl_header_generator AGG_ctrl_header::AGG_ctrl_header_generator::sample;


class DIS_ctrl_header : public header{
        DIS_ctrl_header(DIS_ctrl_header&){} // cannot be called by users
        
    protected:
        DIS_ctrl_header(){} // this constructor cannot be directly called by users

    public:
        ~DIS_ctrl_header(){}
        string type() { return "DIS_ctrl_header"; }

        class DIS_ctrl_header_generator;
        friend class DIS_ctrl_header_generator;
        // DIS_ctrl_header_generator is derived from header_generator to generate a header
        class DIS_ctrl_header_generator : public header_generator{
                static DIS_ctrl_header_generator sample;
                // this constructor is only for sample to register this header type
                DIS_ctrl_header_generator() { /*cout << "DIS_ctrl_header registered" << endl;*/ register_header_type(&sample); }
            protected:
                virtual header * generate(){
                    // cout << "DIS_ctrl_header generated" << endl;
                    return new DIS_ctrl_header; 
                }
            public:
                virtual string type() { return "DIS_ctrl_header";}
                ~DIS_ctrl_header_generator(){}
        
        };
};
DIS_ctrl_header::DIS_ctrl_header_generator DIS_ctrl_header::DIS_ctrl_header_generator::sample;

// MARK: Payload
class payload {
        payload(payload&){} // this constructor cannot be directly called by users
        
        string msg;
        
    protected:
        payload(){}
    public:
        virtual ~payload(){}
        virtual string type() = 0;
        
        SET(setMsg,string,msg,_msg);
        GET(getMsg,string,msg);
        
        class payload_generator {
                // lock the copy constructor
                payload_generator(payload_generator &){}
                // store all possible types of header
                static map<string,payload_generator*> prototypes;
            protected:
                // allow derived class to use it
                payload_generator() {}
                // after you create a new payload type, please register the factory of this payload type by this function
                void register_payload_type(payload_generator *h) { prototypes[h->type()] = h; }
                // you have to implement your own generate() to generate your payload
                virtual payload* generate() = 0;
            public:
                // you have to implement your own type() to return your header type
        	    virtual string type() = 0;
        	    // this function is used to generate any type of header derived
        	    static payload * generate (string type) {
            		if(prototypes.find(type) != prototypes.end()){ // if this type derived exists 
            			return prototypes[type]->generate(); // generate it!!
            		}
            		std::cerr << "no such payload type" << std::endl; // otherwise
            		return nullptr;
            	}
            	static void print () {
            	    cout << "registered payload types: " << endl;
            	    for (map<string,payload::payload_generator*>::iterator it = prototypes.begin(); it != prototypes.end(); it ++)
            	        cout << it->second->type() << endl;
            	}
            	virtual ~payload_generator(){};
        };
};
map<string,payload::payload_generator*> payload::payload_generator::prototypes;


class IoT_data_payload : public payload {
        IoT_data_payload(IoT_data_payload&){}

    protected:
        IoT_data_payload(){} // this constructor cannot be directly called by users
    public:
        ~IoT_data_payload(){}
        
        string type() { return "IoT_data_payload"; }
        
        class IoT_data_payload_generator;
        friend class IoT_data_payload_generator;
        // IoT_data_payload is derived from payload_generator to generate a payload
        class IoT_data_payload_generator : public payload_generator{
                static IoT_data_payload_generator sample;
                // this constructor is only for sample to register this payload type
                IoT_data_payload_generator() { /*cout << "IoT_data_payload registered" << endl;*/ register_payload_type(&sample); }
            protected:
                virtual payload * generate(){ 
                    // cout << "IoT_data_payload generated" << endl;
                    return new IoT_data_payload; 
                }
            public:
                virtual string type() { return "IoT_data_payload";}
                ~IoT_data_payload_generator(){}
        };
};
IoT_data_payload::IoT_data_payload_generator IoT_data_payload::IoT_data_payload_generator::sample;

class IoT_ctrl_payload : public payload {
        IoT_ctrl_payload(IoT_ctrl_payload & s): counter (s.counter) {}
        
        unsigned int counter ;
        unsigned int parent;
        
    protected:
        IoT_ctrl_payload(): counter (0) {} // this constructor cannot be directly called by users
    public:
        ~IoT_ctrl_payload(){}
        
        void increase() { counter ++; } // used to increase the counter
        GET(getCounter,unsigned int,counter); // used to get the value of counter
        GET(getParent,unsigned int,parent); // used to get the value of parent
        SET(setParent,unsigned int,parent,n_parent);

        string type() { return "IoT_ctrl_payload"; }
        
        
        class IoT_ctrl_payload_generator;
        friend class IoT_ctrl_payload_generator;
        // IoT_data_payload is derived from payload_generator to generate a payload
        class IoT_ctrl_payload_generator : public payload_generator{
                static IoT_ctrl_payload_generator sample;
                // this constructor is only for sample to register this payload type
                IoT_ctrl_payload_generator() { /*cout << "IoT_ctrl_payload registered" << endl;*/ register_payload_type(&sample); }
            protected:
                virtual payload * generate(){ 
                    // cout << "IoT_ctrl_payload generated" << endl;
                    return new IoT_ctrl_payload; 
                }
            public:
                virtual string type() { return "IoT_ctrl_payload";}
                ~IoT_ctrl_payload_generator(){}
        };
};
IoT_ctrl_payload::IoT_ctrl_payload_generator IoT_ctrl_payload::IoT_ctrl_payload_generator::sample;


class AGG_ctrl_payload : public payload {
        AGG_ctrl_payload(AGG_ctrl_payload & s) {}
        
        
    protected:
        AGG_ctrl_payload() {} // this constructor cannot be directly called by users
    public:
        ~AGG_ctrl_payload(){}
        
        // void increase() { counter ++; } // used to increase the counter
        // GET(getCounter,unsigned int,counter); // used to get the value of counter
        
        string type() { return "AGG_ctrl_payload"; }
        
        
        class AGG_ctrl_payload_generator;
        friend class AGG_ctrl_payload_generator;
        // IoT_data_payload is derived from payload_generator to generate a payload
        class AGG_ctrl_payload_generator : public payload_generator{
                static AGG_ctrl_payload_generator sample;
                // this constructor is only for sample to register this payload type
                AGG_ctrl_payload_generator() { /*cout << "AGG_ctrl_payload registered" << endl;*/ register_payload_type(&sample); }
            protected:
                virtual payload * generate(){ 
                    // cout << "AGG_ctrl_payload generated" << endl;
                    return new AGG_ctrl_payload; 
                }
            public:
                virtual string type() { return "AGG_ctrl_payload";}
                ~AGG_ctrl_payload_generator(){}
        };
};
AGG_ctrl_payload::AGG_ctrl_payload_generator AGG_ctrl_payload::AGG_ctrl_payload_generator::sample;


class DIS_ctrl_payload : public payload {
        DIS_ctrl_payload(DIS_ctrl_payload & s): parent(s.parent) {}
        
        // unsigned int counter ;
        unsigned int parent;
        
    protected:
        DIS_ctrl_payload(int _parent=0): parent (_parent) {} // this constructor cannot be directly called by users
    public:
        ~DIS_ctrl_payload(){}
        
        // void increase() { counter ++; } // used to increase the counter
        SET(setParent,unsigned int,parent,_parent);
        GET(getParent,unsigned int,parent); // used to get the value of counter
        
        string type() { return "DIS_ctrl_payload"; }
        
        
        class DIS_ctrl_payload_generator;
        friend class DIS_ctrl_payload_generator;
        // IoT_data_payload is derived from payload_generator to generate a payload
        class DIS_ctrl_payload_generator : public payload_generator{
                static DIS_ctrl_payload_generator sample;
                // this constructor is only for sample to register this payload type
                DIS_ctrl_payload_generator() { /*cout << "DIS_ctrl_payload registered" << endl;*/ register_payload_type(&sample); }
            protected:
                virtual payload * generate(){ 
                    // cout << "DIS_ctrl_payload generated" << endl;
                    return new DIS_ctrl_payload; 
                }
            public:
                virtual string type() { return "DIS_ctrl_payload";}
                ~DIS_ctrl_payload_generator(){}
        };
};
DIS_ctrl_payload::DIS_ctrl_payload_generator DIS_ctrl_payload::DIS_ctrl_payload_generator::sample;

// MARK: Packet
class packet{
        // a packet usually contains a header and a payload
        header *hdr;
        payload *pld;
        unsigned int p_id;
        static unsigned int last_packet_id ; 
        
        packet(packet &) {}
        static int live_packet_num ;
    protected:
        // these constructors cannot be directly called by users
        packet(): hdr(nullptr), pld(nullptr) { p_id=last_packet_id++; live_packet_num ++; }
        packet(string _hdr, string _pld, bool rep = false, unsigned int rep_id = 0) {
            if (! rep ) // a duplicated packet does not have a new packet id
                p_id = last_packet_id ++;
            else
                p_id = rep_id;
            hdr = header::header_generator::generate(_hdr); 
            pld = payload::payload_generator::generate(_pld); 
            live_packet_num ++;
        }
    public:
        virtual ~packet(){ 
            // cout << "packet destructor begin" << endl;
            if (hdr != nullptr) 
                delete hdr; 
            if (pld != nullptr) 
                delete pld; 
            live_packet_num --;
            // cout << "packet destructor end" << endl;
        }
        
        SET(setHeader,header*,hdr,_hdr);
        GET(getHeader,header*,hdr);
        SET(setPayload,payload*,pld,_pld);
        GET(getPayload,payload*,pld);
        GET(getPacketID,unsigned int,p_id);
        
        static void discard ( packet* &p ) {
            // cout << "checking" << endl;
            if (p != nullptr) {
                // cout << "discarding" << endl;
                // cout << p->type() << endl;
                delete p;
                // cout << "discarded" << endl;
            }
            p = nullptr;
            // cout << "checked" << endl;
        }
        virtual string type () = 0;
        // you can define your own packet's addition_information
        // to print more information for recv_event and send_event
        virtual string addition_information () { return ""; }
        
        static int getLivePacketNum () { return live_packet_num; }
        
        class packet_generator;
        friend class packet_generator;
        class packet_generator {
                // lock the copy constructor
                packet_generator(packet_generator &){}
                // store all possible types of packet
                static map<string,packet_generator*> prototypes;
            protected:
                // allow derived class to use it
                packet_generator() {}
                // after you create a new packet type, please register the factory of this payload type by this function
                void register_packet_type(packet_generator *h) { prototypes[h->type()] = h; }
                // you have to implement your own generate() to generate your payload
                virtual packet* generate ( packet *p = nullptr) = 0;
            public:
                // you have to implement your own type() to return your packet type
        	    virtual string type() = 0;
        	    // this function is used to generate any type of packet derived
        	    static packet * generate (string type) {
            		if(prototypes.find(type) != prototypes.end()){ // if this type derived exists 
            			return prototypes[type]->generate(); // generate it!!
            		}
            		std::cerr << "no such packet type" << std::endl; // otherwise
            		return nullptr;
            	}
            	static packet * replicate (packet *p) {
            	    if(prototypes.find(p->type()) != prototypes.end()){ // if this type derived exists 
            			return prototypes[p->type()]->generate(p); // generate it!!
            		}
            		std::cerr << "no such packet type" << std::endl; // otherwise
            		return nullptr;
            	}
            	static void print () {
            	    cout << "registered packet types: " << endl;
            	    for (map<string,packet::packet_generator*>::iterator it = prototypes.begin(); it != prototypes.end(); it ++)
            	        cout << it->second->type() << endl;
            	}
            	virtual ~packet_generator(){};
        };
};
map<string,packet::packet_generator*> packet::packet_generator::prototypes;
unsigned int packet::last_packet_id = 0 ;
int packet::live_packet_num = 0;


// this packet is used to transmit the data
class IoT_data_packet: public packet {
        IoT_data_packet(IoT_data_packet &) {}
        
    protected:
        IoT_data_packet(){} // this constructor cannot be directly called by users
        IoT_data_packet(packet*p): packet(p->getHeader()->type(), p->getPayload()->type(), true, p->getPacketID()) {
            *(dynamic_cast<IoT_data_header*>(this->getHeader())) = *(dynamic_cast<IoT_data_header*> (p->getHeader()));
            *(dynamic_cast<IoT_data_payload*>(this->getPayload())) = *(dynamic_cast<IoT_data_payload*> (p->getPayload()));
            //DFS_path = (dynamic_cast<IoT_data_header*>(p))->DFS_path;
            //isVisited = (dynamic_cast<IoT_data_header*>(p))->isVisited;
        } // for duplicate
        IoT_data_packet(string _h, string _p): packet(_h,_p) {}
        
    public:
        virtual ~IoT_data_packet(){}
        string type() { return "IoT_data_packet"; }
        
        class IoT_data_packet_generator;
        friend class IoT_data_packet_generator;
        // IoT_data_packet is derived from packet_generator to generate a pub packet
        class IoT_data_packet_generator : public packet_generator{
                static IoT_data_packet_generator sample;
                // this constructor is only for sample to register this packet type
                IoT_data_packet_generator() { /*cout << "IoT_data_packet registered" << endl;*/ register_packet_type(&sample); }
            protected:
                virtual packet *generate (packet *p = nullptr){
                    // cout << "IoT_data_packet generated" << endl;
                    if ( nullptr == p )
                        return new IoT_data_packet("IoT_data_header","IoT_data_payload"); 
                    else
                        return new IoT_data_packet(p); // duplicate
                }
            public:
                virtual string type() { return "IoT_data_packet";}
                ~IoT_data_packet_generator(){}
        };
};
IoT_data_packet::IoT_data_packet_generator IoT_data_packet::IoT_data_packet_generator::sample;

// this packet type is used to conduct distributed BFS
class IoT_ctrl_packet: public packet {
        IoT_ctrl_packet(IoT_ctrl_packet &) {}
        
    protected:
        IoT_ctrl_packet(){} // this constructor cannot be directly called by users
        IoT_ctrl_packet(packet*p): packet(p->getHeader()->type(), p->getPayload()->type(), true, p->getPacketID()) {
            *(dynamic_cast<IoT_ctrl_header*>(this->getHeader())) = *(dynamic_cast<IoT_ctrl_header*> (p->getHeader()));
            *(dynamic_cast<IoT_ctrl_payload*>(this->getPayload())) = *(dynamic_cast<IoT_ctrl_payload*> (p->getPayload()));
            //DFS_path = (dynamic_cast<IoT_ctrl_header*>(p))->DFS_path;
            //isVisited = (dynamic_cast<IoT_ctrl_header*>(p))->isVisited;
        } // for duplicate
        IoT_ctrl_packet(string _h, string _p): packet(_h,_p) {}
        
    public:
        virtual ~IoT_ctrl_packet(){}
        string type() { return "IoT_ctrl_packet"; }
        virtual string addition_information() {
            unsigned int counter = (dynamic_cast<IoT_ctrl_payload*>(this->getPayload()))->getCounter();
            // cout << counter << endl;
            return " counter " + to_string(counter);
        }
        
        class IoT_ctrl_packet_generator;
        friend class IoT_ctrl_packet_generator;
        // IoT_ctrl_packet is derived from packet_generator to generate a pub packet
        class IoT_ctrl_packet_generator : public packet_generator{
                static IoT_ctrl_packet_generator sample;
                // this constructor is only for sample to register this packet type
                IoT_ctrl_packet_generator() { /*cout << "IoT_ctrl_packet registered" << endl;*/ register_packet_type(&sample); }
            protected:
                virtual packet *generate (packet *p = nullptr){
                    // cout << "IoT_ctrl_packet generated" << endl;
                    if ( nullptr == p )
                        return new IoT_ctrl_packet("IoT_ctrl_header","IoT_ctrl_payload"); 
                    else
                        return new IoT_ctrl_packet(p); // duplicate
                }
            public:
                virtual string type() { return "IoT_ctrl_packet";}
                ~IoT_ctrl_packet_generator(){}
        };
};
IoT_ctrl_packet::IoT_ctrl_packet_generator IoT_ctrl_packet::IoT_ctrl_packet_generator::sample;



// this packet type is used to transmit each device's nblist to the sink
class AGG_ctrl_packet: public packet {
        AGG_ctrl_packet(AGG_ctrl_packet &) {}
        
    protected:
        AGG_ctrl_packet(){} // this constructor cannot be directly called by users
        AGG_ctrl_packet(packet*p): packet(p->getHeader()->type(), p->getPayload()->type(), true, p->getPacketID()) {
            *(dynamic_cast<AGG_ctrl_header*>(this->getHeader())) = *(dynamic_cast<AGG_ctrl_header*> (p->getHeader()));
            *(dynamic_cast<AGG_ctrl_payload*>(this->getPayload())) = *(dynamic_cast<AGG_ctrl_payload*> (p->getPayload()));
            //DFS_path = (dynamic_cast<AGG_ctrl_header*>(p))->DFS_path;
            //isVisited = (dynamic_cast<AGG_ctrl_header*>(p))->isVisited;
        } // for duplicate
        AGG_ctrl_packet(string _h, string _p): packet(_h,_p) {}
        
    public:
        virtual ~AGG_ctrl_packet(){}
        string type() { return "AGG_ctrl_packet"; }
        
        // virtual string addition_information() {
        //     string msg = (dynamic_cast<AGG_ctrl_payload*>(this->getPayload()))->getMsg();
        //     return " msg " + msg;
        // }
        
        class AGG_ctrl_packet_generator;
        friend class AGG_ctrl_packet_generator;
        // AGG_ctrl_packet is derived from packet_generator to generate a pub packet
        class AGG_ctrl_packet_generator : public packet_generator{
                static AGG_ctrl_packet_generator sample;
                // this constructor is only for sample to register this packet type
                AGG_ctrl_packet_generator() { /*cout << "AGG_ctrl_packet registered" << endl;*/ register_packet_type(&sample); }
            protected:
                virtual packet *generate (packet *p = nullptr){
                    // cout << "AGG_ctrl_packet generated" << endl;
                    if ( nullptr == p )
                        return new AGG_ctrl_packet("AGG_ctrl_header","AGG_ctrl_payload"); 
                    else
                        return new AGG_ctrl_packet(p); // duplicate
                }
            public:
                virtual string type() { return "AGG_ctrl_packet";}
                ~AGG_ctrl_packet_generator(){}
        };
};
AGG_ctrl_packet::AGG_ctrl_packet_generator AGG_ctrl_packet::AGG_ctrl_packet_generator::sample;


// this packet type is used to transmit the new parent to each device
class DIS_ctrl_packet: public packet {
        DIS_ctrl_packet(DIS_ctrl_packet &) {}
        
    protected:
        DIS_ctrl_packet(){} // this constructor cannot be directly called by users
        DIS_ctrl_packet(packet*p): packet(p->getHeader()->type(), p->getPayload()->type(), true, p->getPacketID()) {
            *(dynamic_cast<DIS_ctrl_header*>(this->getHeader())) = *(dynamic_cast<DIS_ctrl_header*> (p->getHeader()));
            *(dynamic_cast<DIS_ctrl_payload*>(this->getPayload())) = *(dynamic_cast<DIS_ctrl_payload*> (p->getPayload()));
            //DFS_path = (dynamic_cast<DIS_ctrl_header*>(p))->DFS_path;
            //isVisited = (dynamic_cast<DIS_ctrl_header*>(p))->isVisited;
        } // for duplicate
        DIS_ctrl_packet(string _h, string _p): packet(_h,_p) {}
        
    public:
        virtual ~DIS_ctrl_packet(){}
        string type() { return "DIS_ctrl_packet"; }
        virtual string addition_information() {
            unsigned int parent = (dynamic_cast<DIS_ctrl_payload*>(this->getPayload()))->getParent();
            // cout << counter << endl;
            return " parent " + to_string(parent);
        }
        
        class DIS_ctrl_packet_generator;
        friend class DIS_ctrl_packet_generator;
        // DIS_ctrl_packet is derived from packet_generator to generate a pub packet
        class DIS_ctrl_packet_generator : public packet_generator{
                static DIS_ctrl_packet_generator sample;
                // this constructor is only for sample to register this packet type
                DIS_ctrl_packet_generator() { /*cout << "DIS_ctrl_packet registered" << endl;*/ register_packet_type(&sample); }
            protected:
                virtual packet *generate (packet *p = nullptr){
                    // cout << "DIS_ctrl_packet generated" << endl;
                    if ( nullptr == p )
                        return new DIS_ctrl_packet("DIS_ctrl_header","DIS_ctrl_payload"); 
                    else
                        return new DIS_ctrl_packet(p); // duplicate
                }
            public:
                virtual string type() { return "DIS_ctrl_packet";}
                ~DIS_ctrl_packet_generator(){}
        };
};
DIS_ctrl_packet::DIS_ctrl_packet_generator DIS_ctrl_packet::DIS_ctrl_packet_generator::sample;



// MARK: Node
class node {
        // all nodes created in the program
        static map<unsigned int, node*> id_node_table;
        unsigned int data_size = 0;
        unsigned int packet_size = 0;
        
        unsigned int id;
        map<unsigned int,bool> phy_neighbors;
        map<unsigned int, unsigned int> reverse_path;
        
    protected:
        node(node&){} // this constructor should not be used
        node(){} // this constructor should not be used
        node(unsigned int _id, unsigned _pkt_sz): id(_id), packet_size(_pkt_sz) { id_node_table[_id] = this; }
    public:
        virtual ~node() { // erase the node
            id_node_table.erase (id) ;
        }
        virtual string type() = 0; // please define it in your derived node class
        
        void add_phy_neighbor (unsigned int _id, string link_type = "simple_link"); // we only add a directed link from id to _id
        void del_phy_neighbor (unsigned int _id); // we only delete a directed link from id to _id
        
        // you can use the function to get the node's neigbhors at this time
        // but in the project 3, you are not allowed to use this function 
        const map<unsigned int,bool> & getPhyNeighbors () { 
            return phy_neighbors;
        }
        
        GET(getPacketSize, unsigned int, packet_size);
        SET(setdataSize, unsigned int, data_size, n_data_size);
        void set_rev_path(unsigned int srcID, unsigned int prevID) { reverse_path[srcID] = prevID; }
        int get_rev_num() { return reverse_path.size(); }
        int get_dst_dir(unsigned int dst) { return reverse_path[dst]; }

        void recv (packet *p) {
            packet *tp = p;
            recv_handler(tp); 
            packet::discard(p); 
        } // the packet will be directly deleted after the handler
        void send (packet *p);
        
        // receive the packet and do something; this is a pure virtual function
        virtual void recv_handler(packet *p) = 0;
        void send_handler(packet *P);
        
        // return pointer to node if node exist, else return nullptr
        static node * id_to_node (unsigned int _id) { return ((id_node_table.find(_id)!=id_node_table.end()) ? id_node_table[_id]: nullptr) ; }
        GET(getNodeID,unsigned int,id);
        
        static void del_node (unsigned int _id) {
            if (id_node_table.find(_id) != id_node_table.end())
                id_node_table.erase(_id);
        }
        static unsigned int getNodeNum () { return id_node_table.size(); }

        class node_generator {
                // lock the copy constructor
                node_generator(node_generator &){}
                // store all possible types of node
                static map<string,node_generator*> prototypes;
            protected:
                // allow derived class to use it
                node_generator() {}
                // after you create a new node type, please register the factory of this node type by this function
                void register_node_type(node_generator *h) { prototypes[h->type()] = h; }
                // you have to implement your own generate() to generate your node
                virtual node* generate(unsigned int _id,unsigned int _pkt_sz) = 0;
            public:
                // you have to implement your own type() to return your node type
                virtual string type() = 0;
        	    // this function is used to generate any type of node derived
        	    static node * generate (string type, unsigned int _id, unsigned int _pkt_sz) {
                    if(id_node_table.find(_id)!=id_node_table.end()){
        	            std::cerr << "duplicate node id" << std::endl; // node id is duplicated
                        return nullptr;
                    }
                    else if ( BROADCAST_ID == _id ) {
                        cerr << "BROADCAST_ID cannot be used" << endl;
                        return nullptr;
                    }
            		else if(prototypes.find(type) != prototypes.end()){ // if this type derived exists 
            		    node * created_node = prototypes[type]->generate(_id, _pkt_sz);
            			return created_node; // generate it!!
                    }
            		std::cerr << "no such node type" << std::endl; // otherwise
                    return nullptr;
                }
                static void print () {
                    cout << "registered node types: " << endl;
                    for (map<string,node::node_generator*>::iterator it = prototypes.begin(); it != prototypes.end(); it ++)
                        cout << it->second->type() << endl;
                }
                virtual ~node_generator(){};
        };
};
map<string,node::node_generator*> node::node_generator::prototypes;
map<unsigned int,node*> node::id_node_table;

class IoT_device: public node {
        // map<unsigned int,bool> one_hop_neighbors; // you can use this variable to record the node's 1-hop neighbors 
        unsigned int parentID = 0;
        unsigned int dis = BROADCAST_ID;
        map<unsigned int,bool> children;
        map<unsigned int, unsigned int> nb_parent;

    protected:
        IoT_device() {} // it should not be used
        IoT_device(IoT_device&) {} // it should not be used
        IoT_device(unsigned int _id, unsigned _pkt_sz): node(_id, _pkt_sz), parentID(_id) {} // this constructor cannot be directly called by users
    
    public:
        ~IoT_device(){}
        string type() { return "IoT_device"; }

        GET(getParentID, unsigned int, parentID);
        SET(setParentID, unsigned int, parentID, n_parent);
        GET(getDis, unsigned int, dis);
        SET(setDis, unsigned int, dis, n_dis);
        void setNbParent(unsigned int _id, unsigned int _parent);
        void device_add_child(unsigned int _id);
        void device_del_child(unsigned int _id);
        void device_mark_sent(unsigned int _id);
        bool device_recv_all();
        
        // please define recv_handler function to deal with the incoming packet
        virtual void recv_handler (packet *p);

        
        // void add_one_hop_neighbor (unsigned int n_id) { one_hop_neighbors[n_id] = true; }
        // unsigned int get_one_hop_neighbor_num () { return one_hop_neighbors.size(); }
        
        class IoT_device_generator;
        friend class IoT_device_generator;
        // IoT_device is derived from node_generator to generate a node
        class IoT_device_generator : public node_generator{
                static IoT_device_generator sample;
                // this constructor is only for sample to register this node type
                IoT_device_generator() { /*cout << "IoT_device registered" << endl;*/ register_node_type(&sample); }
            protected:
                virtual node * generate(unsigned int _id, unsigned int _pkt_sz){ /*cout << "IoT_device generated" << endl;*/ return new IoT_device(_id, _pkt_sz); }
            public:
                virtual string type() { return "IoT_device";}
                ~IoT_device_generator(){}
        };
};
IoT_device::IoT_device_generator IoT_device::IoT_device_generator::sample;

void IoT_device::device_add_child(unsigned int _id) {
    if(children.find(_id) == children.end()){
        children[_id] = false;
    }
}
void IoT_device::device_del_child(unsigned int _id) {
    if(children.find(_id) != children.end()) children.erase(_id);
}
void IoT_device::device_mark_sent(unsigned int _id) {
    children[_id] = true;
}
bool IoT_device::device_recv_all() {
    // watch(getNodeID());
    for (map<unsigned int,bool>::const_iterator it = children.begin(); it != children.end(); it ++) {
        // watch(it->first);
        // watch(it->second);
        if(it->second == false){
            return false;
        }
    }
    return true;
}
void IoT_device::setNbParent(unsigned int _id, unsigned int _parent) {
    // watch(getNodeID());
    // watch(_id);
    // watch(_parent);
    if(nb_parent.find(_id) == nb_parent.end()){
        // debug;
        nb_parent[_id] = _parent;
        if(nb_parent[_id] == getNodeID()) device_add_child(_id);
    }
    else{
        if(nb_parent[_id] > _parent){
            // debug;
            if(nb_parent[_id] == getNodeID()){
                // debug;
                device_del_child(_id);
            }
            else if(_parent == getNodeID()){
                device_add_child(_id);
            }
            nb_parent[_id] = _parent;
        }
        else{
            // do nothing
        }
    }
}


class IoT_sink: public node {
        // map<unsigned int,bool> one_hop_neighbors; // you can use this variable to record the node's 1-hop neighbors 
        unsigned int parent = 0;
        map<unsigned int, unsigned int> nb_parent;

    protected:
        IoT_sink() {} // it should not be used
        IoT_sink(IoT_sink&) {} // it should not be used
        IoT_sink(unsigned int _id, unsigned int _pkt_sz): node(_id, _pkt_sz) {} // this constructor cannot be directly called by users
    
    public:
        ~IoT_sink(){}
        string type() { return "IoT_sink"; }
        
        // please define recv_handler function to deal with the incoming packet
        virtual void recv_handler (packet *p);
        
        void setNbParent(unsigned int _id, unsigned int _parent);
        // void add_one_hop_neighbor (unsigned int n_id) { one_hop_neighbors[n_id] = true; }
        // unsigned int get_one_hop_neighbor_num () { return one_hop_neighbors.size(); }
        
        class IoT_sink_generator;
        friend class IoT_sink_generator;
        // IoT_sink is derived from node_generator to generate a node
        class IoT_sink_generator : public node_generator{
                static IoT_sink_generator sample;
                // this constructor is only for sample to register this node type
                IoT_sink_generator() { /*cout << "IoT_sink registered" << endl;*/ register_node_type(&sample); }
            protected:
                virtual node * generate(unsigned int _id, unsigned int _pkt_sz){ /*cout << "IoT_sink generated" << endl;*/ return new IoT_sink(_id, _pkt_sz); }
            public:
                virtual string type() { return "IoT_sink";}
                ~IoT_sink_generator(){}
        };
};
IoT_sink::IoT_sink_generator IoT_sink::IoT_sink_generator::sample;

void IoT_sink::setNbParent(unsigned int _id, unsigned int _parent) {
    if(nb_parent.find(_id) == nb_parent.end()){
        nb_parent[_id] = _parent;
    }
    else{
        if(nb_parent[_id] > _parent){
            nb_parent[_id] = _parent;
        }
        else{
            // do nothing
        }
    }
}

class mycomp {
    bool reverse;
    
    public:
        mycomp(const bool& revparam = false) { reverse=revparam ; }
        bool operator() (const event* lhs, const event* rhs) const;
};

// MARK: Event
class event {
        event(event*&){} // this constructor cannot be directly called by users
        static priority_queue < event*, vector < event* >, mycomp > events;
        static unsigned int cur_time; // timer
        static unsigned int end_time;
        
        // get the next event
        static event * get_next_event() ;
        static void add_event (event *e) { events.push(e); }
        static hash<string> event_seq;
        
    protected:
        unsigned int trigger_time;
        
        event(){} // it should not be used
        event(unsigned int _trigger_time): trigger_time(_trigger_time) {}

    public:
        virtual void trigger()=0;
        virtual ~event(){}

        virtual unsigned int event_priority() const = 0;
        unsigned int get_hash_value(string string_for_hash) const {
            unsigned int priority = event_seq (string_for_hash);
            return priority;
        }
        
        static void flush_events (); // only for debug
        
        GET(getTriggerTime,unsigned int,trigger_time);
        
        static void start_simulate( unsigned int _end_time ); // the function is used to start the simulation
        
        static unsigned int getCurTime() { return cur_time ; }
        static void getCurTime(unsigned int _cur_time) { cur_time = _cur_time; } 
        // static unsigned int getEndTime() { return end_time ; }
        // static void getEndTime(unsigned int _end_time) { end_time = _end_time; }
        
        virtual void print () const = 0; // the function is used to print the event information

        class event_generator{
                // lock the copy constructor
                event_generator(event_generator &){}
                // store all possible types of event
                static map<string,event_generator*> prototypes;
            protected:
                // allow derived class to use it
                event_generator() {}
                // after you create a new event type, please register the factory of this event type by this function
                void register_event_type(event_generator *h) { prototypes[h->type()] = h; }
                // you have to implement your own generate() to generate your event
                virtual event* generate(unsigned int _trigger_time, void * data) = 0;
            public:
                // you have to implement your own type() to return your event type
                virtual string type() = 0;
        	    // this function is used to generate any type of event derived
        	    static event * generate (string type, unsigned int _trigger_time, void * data) {
            		if(prototypes.find(type) != prototypes.end()){ // if this type derived exists
                        // watch(type);
            		    event * e = prototypes[type]->generate(_trigger_time, data);
                        add_event(e);
            		    return e; // generate it!!
                    }
            		std::cerr << "no such event type" << std::endl; // otherwise
                    return nullptr;
                }
                static void print () {
                    cout << "registered event types: " << endl;
                    for (map<string,event::event_generator*>::iterator it = prototypes.begin(); it != prototypes.end(); it ++)
                        cout << it->second->type() << endl;
                }
                virtual ~event_generator(){}
        };
};
map<string,event::event_generator*> event::event_generator::prototypes;
priority_queue < event*, vector< event* >, mycomp > event::events;
hash<string> event::event_seq;

unsigned int event::cur_time = 0;
unsigned int event::end_time = 0;

void event::flush_events()
{ 
    cout << "**flush begin" << endl;
    while ( ! events.empty() ) {
        cout << setw(11) << events.top()->trigger_time << ": " << setw(11) << events.top()->event_priority() << endl;
        delete events.top();
        events.pop();
    }
    cout << "**flush end" << endl;
}
event * event::get_next_event() {
    if(events.empty()) 
        return nullptr; 
    event * e = events.top();
    events.pop(); 
    // cout << events.size() << " events remains" << endl;
    return e; 
}
void event::start_simulate(unsigned int _end_time) {
    if (_end_time<0) {
        cerr << "you should give a possitive value of _end_time" << endl;
        return;
    }
    end_time = _end_time;
    event *e; 
    e = event::get_next_event ();
    while ( e != nullptr && e->trigger_time <= end_time ) {
        if ( cur_time <= e->trigger_time )
            cur_time = e->trigger_time;
        else {
            cerr << "cur_time = " << cur_time << ", event trigger_time = " << e->trigger_time << endl;
            break;
        }

        // cout << "event trigger_time = " << e->trigger_time << endl;
        e->print(); // for log
        // cout << " event begin" << endl;
        e->trigger();
        // cout << " event end" << endl;
        delete e;
        e = event::get_next_event ();
    }
    // cout << "no more event" << endl;
}

bool mycomp::operator() (const event* lhs, const event* rhs) const {
    // cout << lhs->getTriggerTime() << ", " << rhs->getTriggerTime() << endl;
    // cout << lhs->type() << ", " << rhs->type() << endl;
    unsigned int lhs_pri = lhs->event_priority();
    unsigned int rhs_pri = rhs->event_priority();
    // cout << "lhs hash = " << lhs_pri << endl;
    // cout << "rhs hash = " << rhs_pri << endl;
    
    if (reverse) 
        return ((lhs->getTriggerTime()) == (rhs->getTriggerTime())) ? (lhs_pri < rhs_pri): ((lhs->getTriggerTime()) < (rhs->getTriggerTime()));
    else 
        return ((lhs->getTriggerTime()) == (rhs->getTriggerTime())) ? (lhs_pri > rhs_pri): ((lhs->getTriggerTime()) > (rhs->getTriggerTime()));
}

class recv_event: public event {
    public:
        class recv_data; // forward declaration
            
    private:
        recv_event(recv_event&) {} // this constructor cannot be used
        recv_event() {} // we don't allow users to new a recv_event by themselv
        unsigned int senderID; // the sender
        unsigned int receiverID; // the receiver; the packet will be given to the receiver
        packet *pkt; // the packet
        
    protected:
        // this constructor cannot be directly called by users; only by generator
        recv_event(unsigned int _trigger_time, void *data): event(_trigger_time), senderID(BROADCAST_ID), receiverID(BROADCAST_ID), pkt(nullptr){
            recv_data * data_ptr = (recv_data*) data;
            senderID = data_ptr->s_id;
            receiverID = data_ptr->r_id; // the packet will be given to the receiver

            // watch(receiverID);
            pkt = data_ptr->_pkt;
        } 
        
    public:
        virtual ~recv_event(){}
        // recv_event will trigger the recv function
        virtual void trigger();
        
        unsigned int event_priority() const;
        
        class recv_event_generator;
        friend class recv_event_generator;
        // recv_event is derived from event_generator to generate a event
        class recv_event_generator : public event_generator{
                static recv_event_generator sample;
                // this constructor is only for sample to register this event type
                recv_event_generator() { /*cout << "recv_event registered" << endl;*/ register_event_type(&sample); }
            protected:
                virtual event * generate(unsigned int _trigger_time, void *data){ 
                    // cout << "recv_event generated" << endl; 
                    return new recv_event(_trigger_time, data); 
                }
                
            public:
                virtual string type() { return "recv_event";}
                ~recv_event_generator(){}
        };
        // this class is used to initialize the recv_event
        class recv_data{
            public:
                unsigned int s_id;
                unsigned int r_id;
                packet *_pkt;
        };
        
        void print () const;
};
recv_event::recv_event_generator recv_event::recv_event_generator::sample;

void recv_event::trigger() {
    if (pkt == nullptr) {
        cerr << "recv_event error: no pkt!" << endl; 
        return ; 
    }
    else if (node::id_to_node(receiverID) == nullptr){
        cerr << "recv_event error: no node " << receiverID << "!" << endl;
        delete pkt; return ;
    }
    node::id_to_node(receiverID)->recv(pkt); 
    // watch(receiverID);
}
unsigned int recv_event::event_priority() const {
    string string_for_hash;
    string_for_hash = to_string(getTriggerTime()) + to_string(senderID) + to_string (receiverID) + to_string (pkt->getPacketID());
    return get_hash_value(string_for_hash);
}
// the recv_event::print() function is used for log file
void recv_event::print () const {
    cout << "time "          << setw(11) << event::getCurTime() 
         << "   recID"       << setw(11) << receiverID 
         << "   pktID"       << setw(11) << pkt->getPacketID()
         << "   srcID"       << setw(11) << pkt->getHeader()->getSrcID() 
         << "   dstID"       << setw(11) << pkt->getHeader()->getDstID() 
         << "   preID"       << setw(11) << pkt->getHeader()->getPreID()
         << "   nexID"       << setw(11) << pkt->getHeader()->getNexID()
         << "   "            << pkt->type()
         << pkt->addition_information();
//  if ( pkt->type() == "IoT_ctrl_packet" ) cout << "   " << ((IoT_ctrl_payload*)pkt->getPayload())->getCounter();
         cout << endl;
    // cout << pkt->type()
    //      << "   time "       << setw(11) << event::getCurTime() 
    //      << "   recID "      << setw(11) << receiverID 
    //      << "   pktID"       << setw(11) << pkt->getPacketID()
    //      << "   srcID "      << setw(11) << pkt->getHeader()->getSrcID() 
    //      << "   dstID"       << setw(11) << pkt->getHeader()->getDstID() 
    //      << "   preID"       << setw(11) << pkt->getHeader()->getPreID()
    //      << "   nexID"       << setw(11) << pkt->getHeader()->getNexID()
    //      << endl;
}

class send_event: public event {
    public:
        class send_data; // forward declaration
            
    private:
        send_event (send_event &){}
        send_event (){} // we don't allow users to new a recv_event by themselves
        // this constructor cannot be directly called by users; only by generator
        unsigned int senderID; // the sender
        unsigned int receiverID; // the receiver 
        packet *pkt; // the packet
    
    protected:
        send_event (unsigned int _trigger_time, void *data): event(_trigger_time), senderID(BROADCAST_ID), receiverID(BROADCAST_ID), pkt(nullptr){
            send_data * data_ptr = (send_data*) data;
            senderID = data_ptr->s_id;
            receiverID = data_ptr->r_id;
            pkt = data_ptr->_pkt;
        } 
        
    public:
        virtual ~send_event(){}
        // send_event will trigger the send function
        virtual void trigger();
        
        unsigned int event_priority() const;
        
        class send_event_generator;
        friend class send_event_generator;
        // send_event is derived from event_generator to generate a event
        class send_event_generator : public event_generator{
                static send_event_generator sample;
                // this constructor is only for sample to register this event type
                send_event_generator() { /*cout << "send_event registered" << endl;*/ register_event_type(&sample); }
            protected:
                virtual event * generate(unsigned int _trigger_time, void *data){ 
                    // cout << "send_event generated" << endl; 
                    return new send_event(_trigger_time, data); 
                }
            
            public:
                virtual string type() { return "send_event";}
                ~send_event_generator(){}
        };
        // this class is used to initialize the send_event
        class send_data{
            public:
                unsigned int s_id;
                unsigned int r_id;
                packet *_pkt;
                unsigned int t;
        };
        
        void print () const;
};
send_event::send_event_generator send_event::send_event_generator::sample;

void send_event::trigger() {
    if (pkt == nullptr) {
        cerr << "send_event error: no pkt!" << endl; 
        return ; 
    }
    else if (node::id_to_node(senderID) == nullptr){
        cerr << "send_event error: no node " << senderID << "!" << endl;
        delete pkt; return ;
    }
    node::id_to_node(senderID)->send(pkt);
}
unsigned int send_event::event_priority() const {
    string string_for_hash;
    string_for_hash = to_string(getTriggerTime()) + to_string(senderID) + to_string (receiverID) + to_string (pkt->getPacketID());
    return get_hash_value(string_for_hash);
}
// the send_event::print() function is used for log file
void send_event::print () const {
    cout << "time "          << setw(11) << event::getCurTime() 
         << "   senID"       << setw(11) << senderID 
         << "   pktID"       << setw(11) << pkt->getPacketID()
         << "   srcID"       << setw(11) << pkt->getHeader()->getSrcID() 
         << "   dstID"       << setw(11) << pkt->getHeader()->getDstID() 
         << "   preID"       << setw(11) << pkt->getHeader()->getPreID()
         << "   nexID"       << setw(11) << pkt->getHeader()->getNexID()
         << "   "            << pkt->type()
         << pkt->addition_information()
         //<< "   msg"         << setw(11) << dynamic_cast<IoT_data_payload*>(pkt->getPayload())->getMsg()
         << endl;
    // cout << pkt->type()
    //      << "   time "       << setw(11) << event::getCurTime() 
    //      << "   senID "      << setw(11) << senderID
    //      << "   pktID"       << setw(11) << pkt->getPacketID()
    //      << "   srcID "      << setw(11) << pkt->getHeader()->getSrcID() 
    //      << "   dstID"       << setw(11) << pkt->getHeader()->getDstID() 
    //      << "   preID"       << setw(11) << pkt->getHeader()->getPreID()
    //      << "   nexID"       << setw(11) << pkt->getHeader()->getNexID()
    //      << endl;
}

////////////////////////////////////////////////////////////////////////////////

class IoT_data_pkt_gen_event: public event {
    public:
        class gen_data; // forward declaration
            
    private:
        IoT_data_pkt_gen_event (IoT_data_pkt_gen_event &){}
        IoT_data_pkt_gen_event (){} // we don't allow users to new a IoT_data_pkt_gen_event by themselves
        // this constructor cannot be directly called by users; only by generator
        unsigned int src; // the src
        unsigned int dst; // the dst 
        // packet *pkt; // the packet
        string msg;
    
    protected:
        IoT_data_pkt_gen_event (unsigned int _trigger_time, void *data): event(_trigger_time), src(BROADCAST_ID), dst(BROADCAST_ID){
            pkt_gen_data * data_ptr = (pkt_gen_data*) data;
            src = data_ptr->src_id;
            dst = data_ptr->dst_id;
            // pkt = data_ptr->_pkt;
            msg = data_ptr->msg;
        } 
        
    public:
        virtual ~IoT_data_pkt_gen_event(){}
        // IoT_data_pkt_gen_event will trigger the packet gen function
        virtual void trigger();
        
        unsigned int event_priority() const;
        
        class IoT_data_pkt_gen_event_generator;
        friend class IoT_data_pkt_gen_event_generator;
        // IoT_data_pkt_gen_event_generator is derived from event_generator to generate an event
        class IoT_data_pkt_gen_event_generator : public event_generator{
                static IoT_data_pkt_gen_event_generator sample;
                // this constructor is only for sample to register this event type
                IoT_data_pkt_gen_event_generator() { /*cout << "send_event registered" << endl;*/ register_event_type(&sample); }
            protected:
                virtual event * generate(unsigned int _trigger_time, void *data){ 
                    // cout << "send_event generated" << endl; 
                    return new IoT_data_pkt_gen_event(_trigger_time, data); 
                }
            
            public:
                virtual string type() { return "IoT_data_pkt_gen_event";}
                ~IoT_data_pkt_gen_event_generator(){}
        };
        // this class is used to initialize the IoT_data_pkt_gen_event
        class pkt_gen_data{
            public:
                unsigned int src_id;
                unsigned int dst_id;
                string msg;
                // packet *_pkt;
        };
        
        void print () const;
};
IoT_data_pkt_gen_event::IoT_data_pkt_gen_event_generator IoT_data_pkt_gen_event::IoT_data_pkt_gen_event_generator::sample;

void IoT_data_pkt_gen_event::trigger() {
    if (node::id_to_node(src) == nullptr){
        cerr << "IoT_data_pkt_gen_event error: no node " << src << "!" << endl;
        return ;
    }
    else if ( dst != BROADCAST_ID && node::id_to_node(dst) == nullptr ) {
        cerr << "IoT_data_pkt_gen_event error: no node " << dst << "!" << endl;
        return;
    }
    
    IoT_data_packet *pkt = dynamic_cast<IoT_data_packet*> ( packet::packet_generator::generate("IoT_data_packet") );
    if (pkt == nullptr) { 
        cerr << "packet type is incorrect" << endl; return; 
    }
    IoT_data_header *hdr = dynamic_cast<IoT_data_header*> ( pkt->getHeader() );
    IoT_data_payload *pld = dynamic_cast<IoT_data_payload*> ( pkt->getPayload() );
    
    if (hdr == nullptr) {
        cerr << "header type is incorrect" << endl; return ;
    }
    if (pld == nullptr) {
        cerr << "payload type is incorrect" << endl; return ;
    }

    hdr->setSrcID(src);
    hdr->setDstID(dst);
    hdr->setPreID(src); // this column is not important when the packet is first received by the src (i.e., just generated)
    hdr->setNexID(src); // this column is not important when the packet is first received by the src (i.e., just generated)

    pld->setMsg(msg);
    
    recv_event::recv_data e_data;
    e_data.s_id = src;
    e_data.r_id = src; // to make the packet start from the src
    e_data._pkt = pkt;
    
    recv_event *e = dynamic_cast<recv_event*> ( event::event_generator::generate("recv_event", trigger_time, (void *)&e_data) );

}
unsigned int IoT_data_pkt_gen_event::event_priority() const {
    string string_for_hash;
    string_for_hash = to_string(getTriggerTime()) + to_string(src) + to_string (dst) ; //to_string (pkt->getPacketID());
    return get_hash_value(string_for_hash);
}
// the IoT_data_pkt_gen_event::print() function is used for log file
void IoT_data_pkt_gen_event::print () const {
    cout << "time "          << setw(11) << event::getCurTime() 
         << "        "       << setw(11) << " "
         << "        "       << setw(11) << " "
         << "   srcID"       << setw(11) << src
         << "   dstID"       << setw(11) << dst
         << "        "       << setw(11) << " "
         << "        "       << setw(11) << " "
         << "   IoT_data_packet generating"
         << endl;
}

class IoT_ctrl_pkt_gen_event: public event {
    public:
        class gen_data; // forward declaration
            
    private:
        IoT_ctrl_pkt_gen_event (IoT_ctrl_pkt_gen_event &){}
        IoT_ctrl_pkt_gen_event (){} // we don't allow users to new a IoT_ctrl_pkt_gen_event by themselves
        // this constructor cannot be directly called by users; only by generator
        unsigned int src; // the src
        unsigned int dst; // the dst 
        // unsigned int mat;
        // unsigned int act;
        // packet *pkt; // the packet
        string msg;
        // double per; // percentage
    
    protected:
        IoT_ctrl_pkt_gen_event (unsigned int _trigger_time, void *data): event(_trigger_time), src(BROADCAST_ID), dst(BROADCAST_ID){
            pkt_gen_data * data_ptr = (pkt_gen_data*) data;
            src = data_ptr->src_id;
            dst = data_ptr->dst_id;
            // pkt = data_ptr->_pkt;
            // mat = data_ptr->mat_id;
            // act = data_ptr->act_id;
            msg = data_ptr->msg;
            // per = data_ptr->per;
        } 
        
    public:
        virtual ~IoT_ctrl_pkt_gen_event(){}
        // IoT_ctrl_pkt_gen_event will trigger the packet gen function
        virtual void trigger();
        
        unsigned int event_priority() const;
        
        class IoT_ctrl_pkt_gen_event_generator;
        friend class IoT_ctrl_pkt_gen_event_generator;
        // IoT_ctrl_pkt_gen_event_generator is derived from event_generator to generate an event
        class IoT_ctrl_pkt_gen_event_generator : public event_generator{
                static IoT_ctrl_pkt_gen_event_generator sample;
                // this constructor is only for sample to register this event type
                IoT_ctrl_pkt_gen_event_generator() { /*cout << "send_event registered" << endl;*/ register_event_type(&sample); }
            protected:
                virtual event * generate(unsigned int _trigger_time, void *data){ 
                    // cout << "send_event generated" << endl; 
                    return new IoT_ctrl_pkt_gen_event(_trigger_time, data); 
                }
            
            public:
                virtual string type() { return "IoT_ctrl_pkt_gen_event";}
                ~IoT_ctrl_pkt_gen_event_generator(){}
        };
        // this class is used to initialize the IoT_ctrl_pkt_gen_event
        class pkt_gen_data{
            public:
                unsigned int src_id; // the sink
                unsigned int dst_id; // the node that should update its rule
                // unsigned int mat_id; // the target of the rule
                // unsigned int act_id; // the next hop toward the target recorded in the rule
                string msg;
                // double per; // the percentage
                // packet *_pkt;
        };
        
        void print () const;
};
IoT_ctrl_pkt_gen_event::IoT_ctrl_pkt_gen_event_generator IoT_ctrl_pkt_gen_event::IoT_ctrl_pkt_gen_event_generator::sample;

void IoT_ctrl_pkt_gen_event::trigger() {
    
    IoT_ctrl_packet *pkt = dynamic_cast<IoT_ctrl_packet*> ( packet::packet_generator::generate("IoT_ctrl_packet") );
    if (pkt == nullptr) { 
        cerr << "packet type is incorrect" << endl; return; 
    }
    IoT_ctrl_header *hdr = dynamic_cast<IoT_ctrl_header*> ( pkt->getHeader() );
    IoT_ctrl_payload *pld = dynamic_cast<IoT_ctrl_payload*> ( pkt->getPayload() );
    
    if (hdr == nullptr) {
        cerr << "header type is incorrect" << endl; return ;
    }
    if (pld == nullptr) {
        cerr << "payload type is incorrect" << endl; return ;
    }

    hdr->setSrcID(src); 
    hdr->setDstID(dst);
    hdr->setPreID(src);
    hdr->setNexID(src);
    
    // payload
    pld->setMsg(msg);
    // pld->setMatID(mat);
    // pld->setActID(act);
    // pld->setPer(per);
    
    recv_event::recv_data e_data;
    e_data.s_id = src;
    e_data.r_id = src;
    e_data._pkt = pkt;
    
    
    recv_event *e = dynamic_cast<recv_event*> ( event::event_generator::generate("recv_event",trigger_time, (void *)&e_data) );
}
unsigned int IoT_ctrl_pkt_gen_event::event_priority() const {
    string string_for_hash;
    // string_for_hash = to_string(getTriggerTime()) + to_string(src) + to_string(dst) + to_string(mat) + to_string(act); //to_string (pkt->getPacketID());
    string_for_hash = to_string(getTriggerTime()) + to_string(src) + to_string(dst) ; //to_string (pkt->getPacketID());
    return get_hash_value(string_for_hash);
}
// the IoT_ctrl_pkt_gen_event::print() function is used for log file
void IoT_ctrl_pkt_gen_event::print () const {
    cout << "time "          << setw(11) << event::getCurTime() 
         << "        "       << setw(11) << " "
         << "        "       << setw(11) << " "
         << "   srcID"       << setw(11) << src
         << "   dstID"       << setw(11) << dst
         << "        "       << setw(11) << " "
         << "        "       << setw(11) << " "
        //  << "   matID"       << setw(11) << mat
        //  << "   actID"       << setw(11) << act
         << "   IoT_ctrl_packet generating"
         << endl;
}



class AGG_ctrl_pkt_gen_event: public event {
    public:
        class gen_data; // forward declaration
            
    private:
        AGG_ctrl_pkt_gen_event (AGG_ctrl_pkt_gen_event &){}
        AGG_ctrl_pkt_gen_event (){} // we don't allow users to new a AGG_ctrl_pkt_gen_event by themselves
        // this constructor cannot be directly called by users; only by generator
        unsigned int src; // the src
        unsigned int dst; // the dst 
        // unsigned int mat;
        // unsigned int act;
        // packet *pkt; // the packet
        string msg;
        // double per; // percentage
    
    protected:
        AGG_ctrl_pkt_gen_event (unsigned int _trigger_time, void *data): event(_trigger_time), src(BROADCAST_ID), dst(BROADCAST_ID){
            pkt_gen_data * data_ptr = (pkt_gen_data*) data;
            src = data_ptr->src_id;
            dst = data_ptr->dst_id;
            // pkt = data_ptr->_pkt;
            // mat = data_ptr->mat_id;
            // act = data_ptr->act_id;
            msg = data_ptr->msg;
            // per = data_ptr->per;
        } 
        
    public:
        virtual ~AGG_ctrl_pkt_gen_event(){}
        // AGG_ctrl_pkt_gen_event will trigger the packet gen function
        virtual void trigger();
        
        unsigned int event_priority() const;
        
        class AGG_ctrl_pkt_gen_event_generator;
        friend class AGG_ctrl_pkt_gen_event_generator;
        // AGG_ctrl_pkt_gen_event_generator is derived from event_generator to generate an event
        class AGG_ctrl_pkt_gen_event_generator : public event_generator{
                static AGG_ctrl_pkt_gen_event_generator sample;
                // this constructor is only for sample to register this event type
                AGG_ctrl_pkt_gen_event_generator() { /*cout << "send_event registered" << endl;*/ register_event_type(&sample); }
            protected:
                virtual event * generate(unsigned int _trigger_time, void *data){ 
                    // cout << "send_event generated" << endl; 
                    return new AGG_ctrl_pkt_gen_event(_trigger_time, data); 
                }
            
            public:
                virtual string type() { return "AGG_ctrl_pkt_gen_event";}
                ~AGG_ctrl_pkt_gen_event_generator(){}
        };
        // this class is used to initialize the AGG_ctrl_pkt_gen_event
        class pkt_gen_data{
            public:
                unsigned int src_id; // the sink
                unsigned int dst_id; // the node that should update its rule
                // unsigned int mat_id; // the target of the rule
                // unsigned int act_id; // the next hop toward the target recorded in the rule
                string msg;
                // double per; // the percentage
                // packet *_pkt;
        };
        
        void print () const;
};
AGG_ctrl_pkt_gen_event::AGG_ctrl_pkt_gen_event_generator AGG_ctrl_pkt_gen_event::AGG_ctrl_pkt_gen_event_generator::sample;

void AGG_ctrl_pkt_gen_event::trigger() {
    
    AGG_ctrl_packet *pkt = dynamic_cast<AGG_ctrl_packet*> ( packet::packet_generator::generate("AGG_ctrl_packet") );
    if (pkt == nullptr) { 
        cerr << "packet type is incorrect" << endl; return; 
    }
    AGG_ctrl_header *hdr = dynamic_cast<AGG_ctrl_header*> ( pkt->getHeader() );
    AGG_ctrl_payload *pld = dynamic_cast<AGG_ctrl_payload*> ( pkt->getPayload() );
    
    if (hdr == nullptr) {
        cerr << "header type is incorrect" << endl; return ;
    }
    if (pld == nullptr) {
        cerr << "payload type is incorrect" << endl; return ;
    }

    hdr->setSrcID(src); 
    hdr->setDstID(dst);
    hdr->setPreID(src);
    hdr->setNexID(src);
    
    // payload
    pld->setMsg(msg);
    // pld->setMatID(mat);
    // pld->setActID(act);
    // pld->setPer(per);
    
    recv_event::recv_data e_data;
    e_data.s_id = src;
    e_data.r_id = src;
    e_data._pkt = pkt;
    
    recv_event *e = dynamic_cast<recv_event*> ( event::event_generator::generate("recv_event",trigger_time, (void *)&e_data) );
}
unsigned int AGG_ctrl_pkt_gen_event::event_priority() const {
    string string_for_hash;
    // string_for_hash = to_string(getTriggerTime()) + to_string(src) + to_string(dst) + to_string(mat) + to_string(act); //to_string (pkt->getPacketID());
    string_for_hash = to_string(getTriggerTime()) + to_string(src) + to_string(dst) ; //to_string (pkt->getPacketID());
    return get_hash_value(string_for_hash);
}
// the AGG_ctrl_pkt_gen_event::print() function is used for log file
void AGG_ctrl_pkt_gen_event::print () const {
    cout << "time "          << setw(11) << event::getCurTime() 
         << "        "       << setw(11) << " "
         << "        "       << setw(11) << " "
         << "   srcID"       << setw(11) << src
         << "   dstID"       << setw(11) << dst
         << "        "       << setw(11) << " "
         << "        "       << setw(11) << " "
        //  << "   matID"       << setw(11) << mat
        //  << "   actID"       << setw(11) << act
         << "   AGG_ctrl_packet generating"
         << endl;
}


class DIS_ctrl_pkt_gen_event: public event {
    public:
        class gen_data; // forward declaration
            
    private:
        DIS_ctrl_pkt_gen_event (DIS_ctrl_pkt_gen_event &){}
        DIS_ctrl_pkt_gen_event (){} // we don't allow users to new a DIS_ctrl_pkt_gen_event by themselves
        // this constructor cannot be directly called by users; only by generator
        unsigned int src; // the src
        unsigned int dst; // the dst 
        // unsigned int mat;
        // unsigned int act;
        // packet *pkt; // the packet
        string msg;
        // double per; // percentage
        int parent;
    
    protected:
        DIS_ctrl_pkt_gen_event (unsigned int _trigger_time, void *data): event(_trigger_time), src(BROADCAST_ID), dst(BROADCAST_ID){
            pkt_gen_data * data_ptr = (pkt_gen_data*) data;
            src = data_ptr->src_id;
            dst = data_ptr->dst_id;
            parent = data_ptr->parent;
            // pkt = data_ptr->_pkt;
            // mat = data_ptr->mat_id;
            // act = data_ptr->act_id;
            msg = data_ptr->msg;
            // per = data_ptr->per;
        } 
        
    public:
        virtual ~DIS_ctrl_pkt_gen_event(){}
        // DIS_ctrl_pkt_gen_event will trigger the packet gen function
        virtual void trigger();
        
        unsigned int event_priority() const;
        
        class DIS_ctrl_pkt_gen_event_generator;
        friend class DIS_ctrl_pkt_gen_event_generator;
        // DIS_ctrl_pkt_gen_event_generator is derived from event_generator to generate an event
        class DIS_ctrl_pkt_gen_event_generator : public event_generator{
                static DIS_ctrl_pkt_gen_event_generator sample;
                // this constructor is only for sample to register this event type
                DIS_ctrl_pkt_gen_event_generator() { /*cout << "send_event registered" << endl;*/ register_event_type(&sample); }
            protected:
                virtual event * generate(unsigned int _trigger_time, void *data){ 
                    // cout << "send_event generated" << endl; 
                    return new DIS_ctrl_pkt_gen_event(_trigger_time, data); 
                }
            
            public:
                virtual string type() { return "DIS_ctrl_pkt_gen_event";}
                ~DIS_ctrl_pkt_gen_event_generator(){}
        };
        // this class is used to initialize the DIS_ctrl_pkt_gen_event
        class pkt_gen_data{
            public:
                unsigned int src_id; // the sink
                unsigned int dst_id; // the node that should update its rule
                // unsigned int mat_id; // the target of the rule
                // unsigned int act_id; // the next hop toward the target recorded in the rule
                unsigned int parent;
                string msg;
                // double per; // the percentage
                // packet *_pkt;
        };
        
        void print () const;
};
DIS_ctrl_pkt_gen_event::DIS_ctrl_pkt_gen_event_generator DIS_ctrl_pkt_gen_event::DIS_ctrl_pkt_gen_event_generator::sample;

void DIS_ctrl_pkt_gen_event::trigger() {
    
    DIS_ctrl_packet *pkt = dynamic_cast<DIS_ctrl_packet*> ( packet::packet_generator::generate("DIS_ctrl_packet") );
    if (pkt == nullptr) { 
        cerr << "packet type is incorrect" << endl; return; 
    }
    DIS_ctrl_header *hdr = dynamic_cast<DIS_ctrl_header*> ( pkt->getHeader() );
    DIS_ctrl_payload *pld = dynamic_cast<DIS_ctrl_payload*> ( pkt->getPayload() );
    
    if (hdr == nullptr) {
        cerr << "header type is incorrect" << endl; return ;
    }
    if (pld == nullptr) {
        cerr << "payload type is incorrect" << endl; return ;
    }

    hdr->setSrcID(src); 
    hdr->setDstID(dst);
    hdr->setPreID(src);
    hdr->setNexID(src);
    
    // payload
    pld->setParent(parent);
    pld->setMsg(msg);
    // pld->setMatID(mat);
    // pld->setActID(act);
    // pld->setPer(per);
    
    recv_event::recv_data e_data;
    e_data.s_id = src;
    e_data.r_id = src;
    e_data._pkt = pkt;
    
    recv_event *e = dynamic_cast<recv_event*> ( event::event_generator::generate("recv_event",trigger_time, (void *)&e_data) );
}
unsigned int DIS_ctrl_pkt_gen_event::event_priority() const {
    string string_for_hash;
    // string_for_hash = to_string(getTriggerTime()) + to_string(src) + to_string(dst) + to_string(mat) + to_string(act); //to_string (pkt->getPacketID());
    string_for_hash = to_string(getTriggerTime()) + to_string(src) + to_string(dst) ; //to_string (pkt->getPacketID());
    return get_hash_value(string_for_hash);
}
// the DIS_ctrl_pkt_gen_event::print() function is used for log file
void DIS_ctrl_pkt_gen_event::print () const {
    cout << "time "          << setw(11) << event::getCurTime() 
         << "        "       << setw(11) << " "
         << "        "       << setw(11) << " "
         << "   srcID"       << setw(11) << src
         << "   dstID"       << setw(11) << dst
         << "        "       << setw(11) << " "
         << "        "       << setw(11) << " "
        //  << "   matID"       << setw(11) << mat
        //  << "   actID"       << setw(11) << act
         << "   DIS_ctrl_packet generating"
         << endl;
}

////////////////////////////////////////////////////////////////////////////////

// MARK: Link 
class link {
        // all links created in the program
        static map< pair<unsigned int,unsigned int>, link*> id_id_link_table;
        
        unsigned int id1; // from
        unsigned int id2; // to
        
    protected:
        link(link&){} // this constructor should not be used
        link(){} // this constructor should not be used
        link(unsigned int _id1, unsigned int _id2): id1(_id1), id2(_id2) { id_id_link_table[pair<unsigned int,unsigned int>(id1,id2)] = this; }

    public:
        virtual ~link() { 
            id_id_link_table.erase (pair<unsigned int,unsigned int>(id1,id2)); // erase the link
        }
        
        static link * id_id_to_link (unsigned int _id1, unsigned int _id2) { 
            return ((id_id_link_table.find(pair<unsigned int,unsigned int>(_id1,_id2))!=id_id_link_table.end()) ? id_id_link_table[pair<unsigned,unsigned>(_id1,_id2)]: nullptr) ; 
        }

        virtual double getLatency() = 0; // you must implement your own latency
        
        static void del_link (unsigned int _id1, unsigned int _id2) {
            pair<unsigned int, unsigned int> temp;
            if (id_id_link_table.find(temp)!=id_id_link_table.end())
                id_id_link_table.erase(temp); 
        }

        static unsigned int getLinkNum () { return id_id_link_table.size(); }

        class link_generator {
                // lock the copy constructor
                link_generator(link_generator &){}
                // store all possible types of link
                static map<string,link_generator*> prototypes;
            protected:
                // allow derived class to use it
                link_generator() {}
                // after you create a new link type, please register the factory of this link type by this function
                void register_link_type(link_generator *h) { prototypes[h->type()] = h; }
                // you have to implement your own generate() to generate your link
                virtual link* generate(unsigned int _id1, unsigned int _id2) = 0;
            public:
                // you have to implement your own type() to return your link type
        	    virtual string type() = 0;
        	    // this function is used to generate any type of link derived
        	    static link * generate (string type, unsigned int _id1, unsigned int _id2) {
        	        if(id_id_link_table.find(pair<unsigned int,unsigned int>(_id1,_id2))!=id_id_link_table.end()){
        	            std::cerr << "duplicate link id" << std::endl; // link id is duplicated
        	            return nullptr;
        	        }
        	        else if ( BROADCAST_ID == _id1 || BROADCAST_ID == _id2 ) {
        	            cerr << "BROADCAST_ID cannot be used" << endl;
        	            return nullptr;
        	        }
            		else if (prototypes.find(type) != prototypes.end()){ // if this type derived exists 
            		    link * created_link = prototypes[type]->generate(_id1,_id2);
            			return created_link; // generate it!!
            		}
            		std::cerr << "no such link type" << std::endl; // otherwise
            		return nullptr;
            	}
            	static void print () {
            	    cout << "registered link types: " << endl;
            	    for (map<string,link::link_generator*>::iterator it = prototypes.begin(); it != prototypes.end(); it ++)
            	        cout << it->second->type() << endl;
            	}
            	virtual ~link_generator(){};
        };
};
map<string,link::link_generator*> link::link_generator::prototypes;
map<pair<unsigned int,unsigned int>, link*> link::id_id_link_table;

void node::add_phy_neighbor (unsigned int _id, string link_type){
    if (id == _id) return; // if the two nodes are the same...
    if (id_node_table.find(_id)==id_node_table.end()) return; // if this node does not exist
    if (phy_neighbors.find(_id)!=phy_neighbors.end()) return; // if this neighbor has been added
    phy_neighbors[_id] = true;
    
    link::link_generator::generate(link_type,id,_id);
}
void node::del_phy_neighbor (unsigned int _id){
    phy_neighbors.erase(_id);
    
}

class simple_link: public link {
    protected:
        simple_link() {} // it should not be used outside the class
        simple_link(simple_link&) {} // it should not be used
        simple_link(unsigned int _id1, unsigned int _id2): link (_id1,_id2){} // this constructor cannot be directly called by users
    
    public:
        virtual ~simple_link() {}
        virtual double getLatency() { return ONE_HOP_DELAY; } // you can implement your own latency
        
        class simple_link_generator;
        friend class simple_link_generator;
        // simple_link is derived from link_generator to generate a link
        class simple_link_generator : public link_generator {
                static simple_link_generator sample;
                // this constructor is only for sample to register this link type
                simple_link_generator() { /*cout << "simple_link registered" << endl;*/ register_link_type(&sample); }
            protected:
                virtual link * generate(unsigned int _id1, unsigned int _id2) 
                { /*cout << "simple_link generated" << endl;*/ return new simple_link(_id1,_id2); }
            public:
                virtual string type() { return "simple_link"; }
                ~simple_link_generator(){}
        };
};

simple_link::simple_link_generator simple_link::simple_link_generator::sample;

// MARK: Global event
// the IoT_data_packet_event function is used to add an initial event
void IoT_data_packet_event (unsigned int src, unsigned int dst=0, unsigned int t = 0, string msg = "default"){
    if ( node::id_to_node(src) == nullptr || (dst != BROADCAST_ID && node::id_to_node(dst) == nullptr) ) {
        cerr << "src or dst is incorrect" << endl; return ;
        return;
    }

    IoT_data_pkt_gen_event::pkt_gen_data e_data;
    e_data.src_id = src;
    e_data.dst_id = dst;
    e_data.msg = msg;
    
    // recv_event *e = dynamic_cast<recv_event*> ( event::event_generator::generate("recv_event",t, (void *)&e_data) );
    IoT_data_pkt_gen_event *e = dynamic_cast<IoT_data_pkt_gen_event*> ( event::event_generator::generate("IoT_data_pkt_gen_event",t, (void *)&e_data) );
    if (e == nullptr) cerr << "event type is incorrect" << endl;
}

// the IoT_ctrl_packet_event function is used to add an initial event

void IoT_ctrl_packet_event (unsigned int src = 0, unsigned int t = event::getCurTime(),
                            string msg = "default") {
        // 1st parameter: the source; the destination that want to broadcast a msg with counter 0 (i.e., match ID)
        // 2nd parameter: time (optional)
        // 3rd parameter: msg (optional)
    if ( node::id_to_node(src) == nullptr ) {
        cerr << "id is incorrect" << endl; return;
    }
    
    // unsigned int src = con_id;
    IoT_ctrl_pkt_gen_event::pkt_gen_data e_data;
    e_data.src_id = src;
    e_data.dst_id = BROADCAST_ID;
    // e_data.mat_id = mat;
    // e_data.act_id = act;
    e_data.msg = msg;
    // e_data.per = per;
    
    IoT_ctrl_pkt_gen_event *e = dynamic_cast<IoT_ctrl_pkt_gen_event*> ( event::event_generator::generate("IoT_ctrl_pkt_gen_event",t, (void *)&e_data) );
    if (e == nullptr) cerr << "event type is incorrect" << endl;
}

// the AGG_ctrl_packet_event function is used to add an initial event
void AGG_ctrl_packet_event (unsigned int src, unsigned int dst=0, unsigned int t = event::getCurTime(), string msg = "default"){
    if ( node::id_to_node(src) == nullptr || (dst != BROADCAST_ID && node::id_to_node(dst) == nullptr) ) {
        cerr << "src or dst is incorrect" << endl; return ;
        return;
    }

    AGG_ctrl_pkt_gen_event::pkt_gen_data e_data;
    e_data.src_id = src;
    e_data.dst_id = dst;
    e_data.msg = msg;
    
    // recv_event *e = dynamic_cast<recv_event*> ( event::event_generator::generate("recv_event",t, (void *)&e_data) );
    AGG_ctrl_pkt_gen_event *e = dynamic_cast<AGG_ctrl_pkt_gen_event*> ( event::event_generator::generate("AGG_ctrl_pkt_gen_event",t, (void *)&e_data) );
    if (e == nullptr) cerr << "event type is incorrect" << endl;
}

// the DIS_ctrl_packet_event function is used to add an initial event
void DIS_ctrl_packet_event (unsigned int sink_id = 0, unsigned int t = event::getCurTime(), string msg = "default"){
    if ( node::id_to_node(sink_id) == nullptr ) {
        cerr << "sink_id or id is incorrect" << endl; return ;
        return;
    }

    DIS_ctrl_pkt_gen_event::pkt_gen_data e_data;
    e_data.src_id = sink_id;
    e_data.dst_id = sink_id;
    e_data.parent = sink_id;
    e_data.msg = msg;
    
    // recv_event *e = dynamic_cast<recv_event*> ( event::event_generator::generate("recv_event",t, (void *)&e_data) );
    DIS_ctrl_pkt_gen_event *e = dynamic_cast<DIS_ctrl_pkt_gen_event*> ( event::event_generator::generate("DIS_ctrl_pkt_gen_event",t, (void *)&e_data) );
    if (e == nullptr) cerr << "event type is incorrect" << endl;
}

// send_handler function is used to transmit packet p based on the information in the header
// Note that the packet p will not be discard after send_handler ()

// MARK: send_handler
void node::send_handler(packet *p){
    packet *_p = packet::packet_generator::replicate(p);
    send_event::send_data e_data;
    e_data.s_id = _p->getHeader()->getPreID();
    e_data.r_id = _p->getHeader()->getNexID();
    e_data._pkt = _p;
    send_event *e = dynamic_cast<send_event*> (event::event_generator::generate("send_event",event::getCurTime(), (void *)&e_data) );
    if (e == nullptr) cerr << "event type is incorrect" << endl;
}

void node::send(packet *p){ // this function is called by event; not for the user
    if (p == nullptr) return;
    
    unsigned int _nexID = p->getHeader()->getNexID();
    for ( map<unsigned int,bool>::iterator it = phy_neighbors.begin(); it != phy_neighbors.end(); it ++) {
        unsigned int nb_id = it->first; // neighbor id
        
        if (nb_id != _nexID && BROADCAST_ID != _nexID) continue; // this neighbor will not receive the packet
        
        unsigned int trigger_time = event::getCurTime() + link::id_id_to_link(id, nb_id)->getLatency() ; // we simply assume that the delay is fixed
        // cout << "node " << id << " send to node " <<  nb_id << endl;
        recv_event::recv_data e_data;
        e_data.s_id = id;    // set the sender   (i.e., preID)
        e_data.r_id = nb_id; // set the receiver (i.e., nexID)
        
        packet *p2 = packet::packet_generator::replicate(p);
        e_data._pkt = p2;
        
        recv_event *e = dynamic_cast<recv_event*> (event::event_generator::generate("recv_event", trigger_time, (void*) &e_data)); // send the packet to the neighbor
        if (e == nullptr) cerr << "event type is incorrect" << endl;
    }
    packet::discard(p);
}


// MARK: recv_handler
void IoT_device::recv_handler (packet *p){
    // in this function, you are "not" allowed to use node::id_to_node(id) !!!!!!!!

    if (p == nullptr) return ;
    
    if (p->type() == "IoT_ctrl_packet") { // the device receives a packet from the sink
        IoT_ctrl_packet *p3 = nullptr;
        p3 = dynamic_cast<IoT_ctrl_packet*> (p);
        IoT_ctrl_payload *l3 = nullptr;
        l3 = dynamic_cast<IoT_ctrl_payload*> (p3->getPayload());

        bool send_packet = false; // to decide weather to send the packet

        setNbParent(p3->getHeader()->getPreID(), l3->getParent());

        if(dis < l3->getCounter()) return;  // return if counter > distance
        else if (dis > l3->getCounter()) {  // reset dis and parent unconditionally if counter < dis
            setDis(l3->getCounter());
            setParentID(p3->getHeader()->getPreID());
            send_packet = true;
        }
        else{                               // check parentID if counter == dis
            if(parentID > p3->getHeader()->getPreID()){
                setParentID(p3->getHeader()->getPreID());
                send_packet = true;
            }
            else return;
        }

        if(send_packet) {

            l3->setParent(p3->getHeader()->getPreID());

            p3->getHeader()->setPreID ( getNodeID() );
            p3->getHeader()->setNexID ( BROADCAST_ID );
            p3->getHeader()->setDstID ( BROADCAST_ID );
            

            l3->increase();
            send_handler(p3);
            // unsigned mat = l3->getMatID();
            // unsigned act = l3->getActID();
            // string msg = l3->getMsg(); // get the msg
        }

    }
    else if (p->type() == "IoT_data_packet" ) { // the device receives a packet
        // cout << "node " << getNodeID() << " send the packet" << endl;

        IoT_data_packet *p3 = nullptr;
        p3 = dynamic_cast<IoT_data_packet*> (p);
        IoT_data_payload *l3 = nullptr;
        l3 = dynamic_cast<IoT_data_payload*> (p3->getPayload());

        bool send_packet = false;

        device_mark_sent(p3->getHeader()->getPreID());
        if(device_recv_all()) send_packet = true;

        // watch(getNodeID());
        // watch(parent);
        // watch(p3->getHeader()->getPreID());

        if(send_packet){
            p3->getHeader()->setPreID ( getNodeID() );
            p3->getHeader()->setNexID ( parentID );
            p3->getHeader()->setDstID ( 0 );
            
            send_handler(p3);
        }
    }
    else if (p->type() == "AGG_ctrl_packet") {
        AGG_ctrl_packet *p3 = nullptr;
        p3 = dynamic_cast<AGG_ctrl_packet*> (p);
        AGG_ctrl_payload *l3 = nullptr;
        l3 = dynamic_cast<AGG_ctrl_payload*> (p3->getPayload());

        set_rev_path(p3->getHeader()->getSrcID(), p3->getHeader()->getPreID());

        string msg = l3->getMsg();
        if(msg == "default") msg = to_string(getNodeID()) + "/" + to_string(getParentID());
        else msg.append(" " + to_string(getNodeID()) + "/" + to_string(getParentID()));

        l3->setMsg(msg);

        p3->getHeader()->setPreID ( getNodeID() );
        p3->getHeader()->setNexID ( getParentID() );
        p3->getHeader()->setDstID ( 0 );

        send_handler(p3);
        
        // cout << "node id = " << getNodeID() << ", msg = "  << l3->getMsg() << endl;
    }
    else if (p->type() == "DIS_ctrl_packet") {
        DIS_ctrl_packet *p3 = nullptr;
        p3 = dynamic_cast<DIS_ctrl_packet*> (p);
        DIS_ctrl_payload *l3 = nullptr;
        l3 = dynamic_cast<DIS_ctrl_payload*> (p3->getPayload());

        if(p3->getHeader()->getDstID() == getNodeID()) return;
        
        p3->getHeader()->setPreID ( getNodeID() );
        p3->getHeader()->setNexID ( get_dst_dir(p3->getHeader()->getDstID()) );

        send_handler(p3);
        // cout << "node id = " << getNodeID() << ", parent = "  << l3->getParent() << endl;
    }
}

void IoT_sink::recv_handler (packet *p){

    if (p == nullptr) return ;
    
    if (p->type() == "IoT_ctrl_packet") { // the device receives a packet from the sink
        IoT_ctrl_packet *p3 = nullptr;
        p3 = dynamic_cast<IoT_ctrl_packet*> (p);
        IoT_ctrl_payload *l3 = nullptr;
        l3 = dynamic_cast<IoT_ctrl_payload*> (p3->getPayload());

        if(p3->getHeader()->getPreID() != 0) return;
        
        p3->getHeader()->setPreID ( getNodeID() );
        p3->getHeader()->setNexID ( BROADCAST_ID );
        p3->getHeader()->setDstID ( BROADCAST_ID );
        
        l3->increase();
        send_handler(p3);
        // unsigned mat = l3->getMatID();
        // unsigned act = l3->getActID();
        // string msg = l3->getMsg(); // get the msg
    }
    else if (p->type() == "IoT_data_packet" ) { // the device receives a packet
        // cout << "node " << getNodeID() << " send the packet" << endl;
    }
    else if (p->type() == "AGG_ctrl_packet") {
        AGG_ctrl_packet *p3 = nullptr;
        p3 = dynamic_cast<AGG_ctrl_packet*> (p);
        AGG_ctrl_payload *l3 = nullptr;
        l3 = dynamic_cast<AGG_ctrl_payload*> (p3->getPayload());

        stringstream stream(l3->getMsg());
        string msg1, msg2;
        int a, b;
        while(!stream.eof()) {
            getline(stream, msg1, '/');
            getline(stream, msg2, ' ');
            a = stoi(msg1);
            b = stoi(msg2);
            // watch(a);
            // watch(b);
            setNbParent(a, b);
        }

        set_rev_path(p3->getHeader()->getSrcID(), p3->getHeader()->getPreID());
        watch(l3->getMsg());
        
        // cout << "node id = " << getNodeID() << ", msg = "  << l3->getMsg() << endl;
    }
    else if (p->type() == "DIS_ctrl_packet") {
        DIS_ctrl_packet *p3 = nullptr;
        p3 = dynamic_cast<DIS_ctrl_packet*> (p);
        DIS_ctrl_payload *l3 = nullptr;
        l3 = dynamic_cast<DIS_ctrl_payload*> (p3->getPayload());
        
        for(int i = 1; i <= get_rev_num(); i++) {

            l3->setParent( nb_parent[i] );
            p3->getHeader()->setPreID ( getNodeID() );
            p3->getHeader()->setNexID ( get_dst_dir(i) );
            p3->getHeader()->setDstID ( i );

            send_handler(p3);
        }
        // cout << "node id = " << getNodeID() << ", parent = "  << l3->getParent() << endl;
    }
}

// MARK: main
int main()
{
    // header::header_generator::print(); // print all registered headers
    // payload::payload_generator::print(); // print all registered payloads
    // packet::packet_generator::print(); // print all registered packets
    // node::node_generator::print(); // print all registered nodes
    // event::event_generator::print(); // print all registered events
    // link::link_generator::print(); // print all registered links 

    unsigned int Nodes, Links, Packet_Size;
    unsigned int SimTime, BFS_Start_Time, AGG_Start_Time;
    unsigned int DIS_Start_Time, Data_Trans_Time;
    cin >> Nodes >> Links >> Packet_Size;
    cin >> SimTime >> BFS_Start_Time >> AGG_Start_Time;
    cin >> DIS_Start_Time >> Data_Trans_Time;

    // generate sink and devices
    node::node_generator::generate("IoT_sink", 0, Packet_Size);
    for(unsigned int id = 1; id < Nodes; id++){
        node::node_generator::generate("IoT_device",id, Packet_Size);
    }

    // set max. data size of a node
    for(unsigned int i = 0, Data_size; i < Nodes; i++){
        cin >> i >> Data_size;
        node::id_to_node(i)->setdataSize(Data_size);
    }
    
    for(unsigned int i = 0, u, v; i < Links; i++) {
        cin >> i >> u >> v;
        // set devices' neighbors
        node::id_to_node(u)->add_phy_neighbor(v);
        node::id_to_node(v)->add_phy_neighbor(u);
    }

    IoT_ctrl_packet_event(0, BFS_Start_Time);
    
    for(unsigned int i = 1; i < Nodes; i++){
        AGG_ctrl_packet_event(i, 0, AGG_Start_Time);
    }
    DIS_ctrl_packet_event(0, DIS_Start_Time);

    // a for-loop let every node send packet to sink (1 ~ n) -> 0
    for(unsigned int i = 1; i < Nodes; i++) {
        IoT_data_packet_event(i, 0, Data_Trans_Time);
    }    
    
    // start simulation!!
    event::start_simulate(SimTime);

    // Print all parent
    cout << 0 << ' ' << 0 << '\n';
    for(unsigned int i = 1; i < Nodes; i++){
        IoT_device* p = dynamic_cast<IoT_device*> (node::id_to_node(i));
        cout << p->getNodeID() << ' ' << p->getParentID() << '\n';
        // watch(node::id_to_node(i)->getPacketSize());
    }
    // event::flush_events();
    // cout << packet::getLivePacketNum() << endl;
    return 0;
}
