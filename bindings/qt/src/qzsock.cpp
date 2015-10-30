/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/

#include "qczmq.h"

///
//  Copy-construct to return the proper wrapped c types
QZsock::QZsock (zsock_t *self, QObject *qObjParent) : QObject (qObjParent)
{
    this->self = self;
}


///
//  Create a new socket. Returns the new socket, or NULL if the new socket
//  could not be created. Note that the symbol zsock_new (and other       
//  constructors/destructors for zsock) are redirected to the *_checked   
//  variant, enabling intelligent socket leak detection. This can have    
//  performance implications if you use a LOT of sockets. To turn off this
//  redirection behaviour, define ZSOCK_NOCHECK.                          
QZsock::QZsock (int type, QObject *qObjParent) : QObject (qObjParent)
{
    this->self = zsock_new (type);
}

///
//  Destroy the socket. You must use this for any socket created via the
//  zsock_new method.                                                   
QZsock::~QZsock ()
{
    zsock_destroy (&self);
}

///
//  Create a PUB socket. Default action is bind.
QZsock * QZsock::newPub (const QString &endpoint)
{
    QZsock *rv = new QZsock (zsock_new_pub (endpoint.toUtf8().data()));
    return rv;
}

///
//  Create a SUB socket, and optionally subscribe to some prefix string. Default
//  action is connect.                                                          
QZsock * QZsock::newSub (const QString &endpoint, const QString &subscribe)
{
    QZsock *rv = new QZsock (zsock_new_sub (endpoint.toUtf8().data(), subscribe.toUtf8().data()));
    return rv;
}

///
//  Create a REQ socket. Default action is connect.
QZsock * QZsock::newReq (const QString &endpoint)
{
    QZsock *rv = new QZsock (zsock_new_req (endpoint.toUtf8().data()));
    return rv;
}

///
//  Create a REP socket. Default action is bind.
QZsock * QZsock::newRep (const QString &endpoint)
{
    QZsock *rv = new QZsock (zsock_new_rep (endpoint.toUtf8().data()));
    return rv;
}

///
//  Create a DEALER socket. Default action is connect.
QZsock * QZsock::newDealer (const QString &endpoint)
{
    QZsock *rv = new QZsock (zsock_new_dealer (endpoint.toUtf8().data()));
    return rv;
}

///
//  Create a ROUTER socket. Default action is bind.
QZsock * QZsock::newRouter (const QString &endpoint)
{
    QZsock *rv = new QZsock (zsock_new_router (endpoint.toUtf8().data()));
    return rv;
}

///
//  Create a PUSH socket. Default action is connect.
QZsock * QZsock::newPush (const QString &endpoint)
{
    QZsock *rv = new QZsock (zsock_new_push (endpoint.toUtf8().data()));
    return rv;
}

///
//  Create a PULL socket. Default action is bind.
QZsock * QZsock::newPull (const QString &endpoint)
{
    QZsock *rv = new QZsock (zsock_new_pull (endpoint.toUtf8().data()));
    return rv;
}

///
//  Create an XPUB socket. Default action is bind.
QZsock * QZsock::newXpub (const QString &endpoint)
{
    QZsock *rv = new QZsock (zsock_new_xpub (endpoint.toUtf8().data()));
    return rv;
}

///
//  Create an XSUB socket. Default action is connect.
QZsock * QZsock::newXsub (const QString &endpoint)
{
    QZsock *rv = new QZsock (zsock_new_xsub (endpoint.toUtf8().data()));
    return rv;
}

///
//  Create a PAIR socket. Default action is connect.
QZsock * QZsock::newPair (const QString &endpoint)
{
    QZsock *rv = new QZsock (zsock_new_pair (endpoint.toUtf8().data()));
    return rv;
}

///
//  Create a STREAM socket. Default action is connect.
QZsock * QZsock::newStream (const QString &endpoint)
{
    QZsock *rv = new QZsock (zsock_new_stream (endpoint.toUtf8().data()));
    return rv;
}

///
//  Create a SERVER socket. Default action is bind.
QZsock * QZsock::newServer (const QString &endpoint)
{
    QZsock *rv = new QZsock (zsock_new_server (endpoint.toUtf8().data()));
    return rv;
}

///
//  Create a CLIENT socket. Default action is connect.
QZsock * QZsock::newClient (const QString &endpoint)
{
    QZsock *rv = new QZsock (zsock_new_client (endpoint.toUtf8().data()));
    return rv;
}

///
//  Bind a socket to a formatted endpoint. For tcp:// endpoints, supports   
//  ephemeral ports, if you specify the port number as "*". By default      
//  zsock uses the IANA designated range from C000 (49152) to FFFF (65535). 
//  To override this range, follow the "*" with "[first-last]". Either or   
//  both first and last may be empty. To bind to a random port within the   
//  range, use "!" in place of "*".                                         
//                                                                          
//  Examples:                                                               
//      tcp://127.0.0.1:*           bind to first free port from C000 up    
//      tcp://127.0.0.1:!           bind to random port from C000 to FFFF   
//      tcp://127.0.0.1:*[60000-]   bind to first free port from 60000 up   
//      tcp://127.0.0.1:![-60000]   bind to random port from C000 to 60000  
//      tcp://127.0.0.1:![55000-55999]                                      
//                                  bind to random port from 55000 to 55999 
//                                                                          
//  On success, returns the actual port number used, for tcp:// endpoints,  
//  and 0 for other transports. On failure, returns -1. Note that when using
//  ephemeral ports, a port may be reused by different services without     
//  clients being aware. Protocols that run on ephemeral ports should take  
//  this into account.                                                      
int QZsock::bind (const QString &param)
{
    int rv = zsock_bind (self, "%s", param.toUtf8().data());
    return rv;
}

///
//  Returns last bound endpoint, if any.
const QString QZsock::endpoint ()
{
    const QString rv = QString (zsock_endpoint (self));
    return rv;
}

///
//  Unbind a socket from a formatted endpoint.                     
//  Returns 0 if OK, -1 if the endpoint was invalid or the function
//  isn't supported.                                               
int QZsock::unbind (const QString &param)
{
    int rv = zsock_unbind (self, "%s", param.toUtf8().data());
    return rv;
}

///
//  Connect a socket to a formatted endpoint        
//  Returns 0 if OK, -1 if the endpoint was invalid.
int QZsock::connect (const QString &param)
{
    int rv = zsock_connect (self, "%s", param.toUtf8().data());
    return rv;
}

///
//  Disconnect a socket from a formatted endpoint                  
//  Returns 0 if OK, -1 if the endpoint was invalid or the function
//  isn't supported.                                               
int QZsock::disconnect (const QString &param)
{
    int rv = zsock_disconnect (self, "%s", param.toUtf8().data());
    return rv;
}

///
//  Attach a socket to zero or more endpoints. If endpoints is not null,     
//  parses as list of ZeroMQ endpoints, separated by commas, and prefixed by 
//  '@' (to bind the socket) or '>' (to connect the socket). Returns 0 if all
//  endpoints were valid, or -1 if there was a syntax error. If the endpoint 
//  does not start with '@' or '>', the serverish argument defines whether   
//  it is used to bind (serverish = true) or connect (serverish = false).    
int QZsock::attach (const QString &endpoints, bool serverish)
{
    int rv = zsock_attach (self, endpoints.toUtf8().data(), serverish);
    return rv;
}

///
//  Returns socket type as printable constant string.
const QString QZsock::typeStr ()
{
    const QString rv = QString (zsock_type_str (self));
    return rv;
}

///
//  Send a 'picture' message to the socket (or actor). The picture is a   
//  string that defines the type of each frame. This makes it easy to send
//  a complex multiframe message in one call. The picture can contain any 
//  of these characters, each corresponding to one or two arguments:      
//                                                                        
//      i = int (signed)                                                  
//      1 = uint8_t                                                       
//      2 = uint16_t                                                      
//      4 = uint32_t                                                      
//      8 = uint64_t                                                      
//      s = char *                                                        
//      b = byte *, size_t (2 arguments)                                  
//      c = zchunk_t *                                                    
//      f = zframe_t *                                                    
//      h = zhashx_t *                                                    
//      U = zuuid_t *                                                     
//      p = void * (sends the pointer value, only meaningful over inproc) 
//      m = zmsg_t * (sends all frames in the zmsg)                       
//      z = sends zero-sized frame (0 arguments)                          
//      u = uint (deprecated)                                             
//                                                                        
//  Note that s, b, c, and f are encoded the same way and the choice is   
//  offered as a convenience to the sender, which may or may not already  
//  have data in a zchunk or zframe. Does not change or take ownership of 
//  any arguments. Returns 0 if successful, -1 if sending failed for any  
//  reason.                                                               
int QZsock::send (const QString &picture,  ...)
{
    va_list args;
    va_start (args, picture);
    int rv = zsock_vsend (self, picture.toUtf8().data(), args);
    va_end (args);
    return rv;
}

///
//  Send a 'picture' message to the socket (or actor). This is a va_list 
//  version of zsock_send (), so please consult its documentation for the
//  details.                                                             
int QZsock::vsend (const QString &picture, va_list argptr)
{
    int rv = zsock_vsend (self, picture.toUtf8().data(), argptr);
    return rv;
}

///
//  Receive a 'picture' message to the socket (or actor). See zsock_send for
//  the format and meaning of the picture. Returns the picture elements into
//  a series of pointers as provided by the caller:                         
//                                                                          
//      i = int * (stores signed integer)                                   
//      4 = uint32_t * (stores 32-bit unsigned integer)                     
//      8 = uint64_t * (stores 64-bit unsigned integer)                     
//      s = char ** (allocates new string)                                  
//      b = byte **, size_t * (2 arguments) (allocates memory)              
//      c = zchunk_t ** (creates zchunk)                                    
//      f = zframe_t ** (creates zframe)                                    
//      U = zuuid_t * (creates a zuuid with the data)                       
//      h = zhashx_t ** (creates zhashx)                                    
//      p = void ** (stores pointer)                                        
//      m = zmsg_t ** (creates a zmsg with the remaing frames)              
//      z = null, asserts empty frame (0 arguments)                         
//      u = uint * (stores unsigned integer, deprecated)                    
//                                                                          
//  Note that zsock_recv creates the returned objects, and the caller must  
//  destroy them when finished with them. The supplied pointers do not need 
//  to be initialized. Returns 0 if successful, or -1 if it failed to recv  
//  a message, in which case the pointers are not modified. When message    
//  frames are truncated (a short message), sets return values to zero/null.
//  If an argument pointer is NULL, does not store any value (skips it).    
//  An 'n' picture matches an empty frame; if the message does not match,   
//  the method will return -1.                                              
int QZsock::recv (const QString &picture,  ...)
{
    va_list args;
    va_start (args, picture);
    int rv = zsock_vrecv (self, picture.toUtf8().data(), args);
    va_end (args);
    return rv;
}

///
//  Receive a 'picture' message from the socket (or actor). This is a    
//  va_list version of zsock_recv (), so please consult its documentation
//  for the details.                                                     
int QZsock::vrecv (const QString &picture, va_list argptr)
{
    int rv = zsock_vrecv (self, picture.toUtf8().data(), argptr);
    return rv;
}

///
//  Return socket routing ID if any. This returns 0 if the socket is not
//  of type ZMQ_SERVER or if no request was already received on it.     
quint32 QZsock::routingId ()
{
    uint32_t rv = zsock_routing_id (self);
    return rv;
}

///
//  Set routing ID on socket. The socket MUST be of type ZMQ_SERVER.        
//  This will be used when sending messages on the socket via the zsock API.
void QZsock::setRoutingId (quint32 routingId)
{
    zsock_set_routing_id (self, (uint32_t) routingId);
    
}

///
//  Set socket to use unbounded pipes (HWM=0); use this in cases when you are
//  totally certain the message volume can fit in memory. This method works  
//  across all versions of ZeroMQ. Takes a polymorphic socket reference.     
void QZsock::setUnbounded ()
{
    zsock_set_unbounded (self);
    
}

///
//  Send a signal over a socket. A signal is a short message carrying a   
//  success/failure code (by convention, 0 means OK). Signals are encoded 
//  to be distinguishable from "normal" messages. Accepts a zock_t or a   
//  zactor_t argument, and returns 0 if successful, -1 if the signal could
//  not be sent. Takes a polymorphic socket reference.                    
int QZsock::signal (byte status)
{
    int rv = zsock_signal (self, status);
    return rv;
}

///
//  Wait on a signal. Use this to coordinate between threads, over pipe  
//  pairs. Blocks until the signal is received. Returns -1 on error, 0 or
//  greater on success. Accepts a zsock_t or a zactor_t as argument.     
//  Takes a polymorphic socket reference.                                
int QZsock::wait ()
{
    int rv = zsock_wait (self);
    return rv;
}

///
//  If there is a partial message still waiting on the socket, remove and    
//  discard it. This is useful when reading partial messages, to get specific
//  message types.                                                           
void QZsock::flush ()
{
    zsock_flush (self);
    
}

///
//  Probe the supplied object, and report if it looks like a zsock_t.
//  Takes a polymorphic socket reference.                            
bool QZsock::is (void *self)
{
    bool rv = zsock_is (self);
    return rv;
}

///
//  Probe the supplied reference. If it looks like a zsock_t instance, return
//  the underlying libzmq socket handle; else if it looks like a file        
//  descriptor, return NULL; else if it looks like a libzmq socket handle,   
//  return the supplied value. Takes a polymorphic socket reference.         
void * QZsock::resolve (void *self)
{
    void * rv = zsock_resolve (self);
    return rv;
}

///
//  Self test of this class
void QZsock::test (bool verbose)
{
    zsock_test (verbose);
    
}
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/