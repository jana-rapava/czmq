/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/
package org.zeromq.czmq;

public class Zproc implements AutoCloseable{
    static {
        try {
            System.loadLibrary ("czmqjni");
        }
        catch (Exception e) {
            System.exit (-1);
        }
    }
    public long self;
    /*
    Create a new zproc.
    NOTE: On Windows and with libzmq3 and libzmq2 this function
    returns NULL. Code needs to be ported there.
    */
    native static long __new ();
    public Zproc () {
        /*  TODO: if __new fails, self is null...            */
        self = __new ();
    }
    public Zproc (long pointer) {
        self = pointer;
    }
    /*
    Destroy zproc, wait until process ends.
    */
    native static void __destroy (long self);
    @Override
    public void close () {
        __destroy (self);
        self = 0;
    }
    /*
    Setup the command line arguments, the first item must be an (absolute) filename
    to run.
    */
    native static void __setArgs (long self, long args);
    public void setArgs (Zlistx args) {
        __setArgs (self, args.self);
    }
    /*
    Setup the environment variables for the process.
    */
    native static void __setEnv (long self, long args);
    public void setEnv (Zhashx args) {
        __setEnv (self, args.self);
    }
    /*
    Connects process stdin with a readable ('>', connect) zeromq socket. If
    socket argument is NULL, zproc creates own managed pair of inproc
    sockets.  The writable one is then accessbile via zproc_stdin method.
    */
    native static void __setStdin (long self, long socket);
    public void setStdin (long socket) {
        __setStdin (self, socket);
    }
    /*
    Connects process stdout with a writable ('@', bind) zeromq socket. If
    socket argument is NULL, zproc creates own managed pair of inproc
    sockets.  The readable one is then accessbile via zproc_stdout method.
    */
    native static void __setStdout (long self, long socket);
    public void setStdout (long socket) {
        __setStdout (self, socket);
    }
    /*
    Connects process stderr with a writable ('@', bind) zeromq socket. If
    socket argument is NULL, zproc creates own managed pair of inproc
    sockets.  The readable one is then accessbile via zproc_stderr method.
    */
    native static void __setStderr (long self, long socket);
    public void setStderr (long socket) {
        __setStderr (self, socket);
    }
    /*
    Return subprocess stdin writable socket. NULL for
    not initialized or external sockets.
    */
    native static long __stdin (long self);
    public long stdin () {
        return __stdin (self);
    }
    /*
    Return subprocess stdout readable socket. NULL for
    not initialized or external sockets.
    */
    native static long __stdout (long self);
    public long stdout () {
        return __stdout (self);
    }
    /*
    Return subprocess stderr readable socket. NULL for
    not initialized or external sockets.
    */
    native static long __stderr (long self);
    public long stderr () {
        return __stderr (self);
    }
    /*
    Starts the process.
    */
    native static int __run (long self);
    public int run () {
        return __run (self);
    }
    /*
    process exit code
    */
    native static int __returncode (long self);
    public int returncode () {
        return __returncode (self);
    }
    /*
    PID of the process
    */
    native static int __pid (long self);
    public int pid () {
        return __pid (self);
    }
    /*
    return true if process is running, false if not yet started or finished
    */
    native static boolean __running (long self);
    public boolean running () {
        return __running (self);
    }
    /*
    wait or poll process status, return return code
    */
    native static int __wait (long self, boolean hang);
    public int Wait (boolean hang) {
        return __wait (self, hang);
    }
    /*
    return internal actor, usefull for the polling if process died
    */
    native static long __actor (long self);
    public long actor () {
        return __actor (self);
    }
    /*
    send a signal to the subprocess
    */
    native static void __kill (long self, int signal);
    public void kill (int signal) {
        __kill (self, signal);
    }
    /*
    set verbose mode
    */
    native static void __setVerbose (long self, boolean verbose);
    public void setVerbose (boolean verbose) {
        __setVerbose (self, verbose);
    }
    /*
    Returns CZMQ version as a single 6-digit integer encoding the major
    version (x 10000), the minor version (x 100) and the patch.
    */
    native static int __czmqVersion ();
    public int czmqVersion () {
        return __czmqVersion ();
    }
    /*
    Returns true if the process received a SIGINT or SIGTERM signal.
    It is good practice to use this method to exit any infinite loop
    processing messages.
    */
    native static boolean __interrupted ();
    public boolean interrupted () {
        return __interrupted ();
    }
    /*
    Returns true if the underlying libzmq supports CURVE security.
    */
    native static boolean __hasCurve ();
    public boolean hasCurve () {
        return __hasCurve ();
    }
    /*
    Return current host name, for use in public tcp:// endpoints.
    If the host name is not resolvable, returns NULL.
    */
    native static String __hostname ();
    public String hostname () {
        return __hostname ();
    }
    /*
    Move the current process into the background. The precise effect
    depends on the operating system. On POSIX boxes, moves to a specified
    working directory (if specified), closes all file handles, reopens
    stdin, stdout, and stderr to the null device, and sets the process to
    ignore SIGHUP. On Windows, does nothing. Returns 0 if OK, -1 if there
    was an error.
    */
    native static void __daemonize (String workdir);
    public void daemonize (String workdir) {
        __daemonize (workdir);
    }
    /*
    Drop the process ID into the lockfile, with exclusive lock, and
    switch the process to the specified group and/or user. Any of the
    arguments may be null, indicating a no-op. Returns 0 on success,
    -1 on failure. Note if you combine this with zsys_daemonize, run
    after, not before that method, or the lockfile will hold the wrong
    process ID.
    */
    native static void __runAs (String lockfile, String group, String user);
    public void runAs (String lockfile, String group, String user) {
        __runAs (lockfile, group, user);
    }
    /*
    Configure the number of I/O threads that ZeroMQ will use. A good
    rule of thumb is one thread per gigabit of traffic in or out. The
    default is 1, sufficient for most applications. If the environment
    variable ZSYS_IO_THREADS is defined, that provides the default.
    Note that this method is valid only before any socket is created.
    */
    native static void __setIoThreads (long ioThreads);
    public void setIoThreads (long ioThreads) {
        __setIoThreads (ioThreads);
    }
    /*
    Configure the number of sockets that ZeroMQ will allow. The default
    is 1024. The actual limit depends on the system, and you can query it
    by using zsys_socket_limit (). A value of zero means "maximum".
    Note that this method is valid only before any socket is created.
    */
    native static void __setMaxSockets (long maxSockets);
    public void setMaxSockets (long maxSockets) {
        __setMaxSockets (maxSockets);
    }
    /*
    Set network interface name to use for broadcasts, particularly zbeacon.
    This lets the interface be configured for test environments where required.
    For example, on Mac OS X, zbeacon cannot bind to 255.255.255.255 which is
    the default when there is no specified interface. If the environment
    variable ZSYS_INTERFACE is set, use that as the default interface name.
    Setting the interface to "*" means "use all available interfaces".
    */
    native static void __setBiface (String value);
    public void setBiface (String value) {
        __setBiface (value);
    }
    /*
    Return network interface to use for broadcasts, or "" if none was set.
    */
    native static String __biface ();
    public String biface () {
        return __biface ();
    }
    /*
    Set log identity, which is a string that prefixes all log messages sent
    by this process. The log identity defaults to the environment variable
    ZSYS_LOGIDENT, if that is set.
    */
    native static void __setLogIdent (String value);
    public void setLogIdent (String value) {
        __setLogIdent (value);
    }
    /*
    Sends log output to a PUB socket bound to the specified endpoint. To
    collect such log output, create a SUB socket, subscribe to the traffic
    you care about, and connect to the endpoint. Log traffic is sent as a
    single string frame, in the same format as when sent to stdout. The
    log system supports a single sender; multiple calls to this method will
    bind the same sender to multiple endpoints. To disable the sender, call
    this method with a null argument.
    */
    native static void __setLogSender (String endpoint);
    public void setLogSender (String endpoint) {
        __setLogSender (endpoint);
    }
    /*
    Enable or disable logging to the system facility (syslog on POSIX boxes,
    event log on Windows). By default this is disabled.
    */
    native static void __setLogSystem (boolean logsystem);
    public void setLogSystem (boolean logsystem) {
        __setLogSystem (logsystem);
    }
    /*
    Log error condition - highest priority
    */
    native static void __logError (String format);
    public void logError (String format) {
        __logError (format);
    }
    /*
    Log warning condition - high priority
    */
    native static void __logWarning (String format);
    public void logWarning (String format) {
        __logWarning (format);
    }
    /*
    Log normal, but significant, condition - normal priority
    */
    native static void __logNotice (String format);
    public void logNotice (String format) {
        __logNotice (format);
    }
    /*
    Log informational message - low priority
    */
    native static void __logInfo (String format);
    public void logInfo (String format) {
        __logInfo (format);
    }
    /*
    Log debug-level message - lowest priority
    */
    native static void __logDebug (String format);
    public void logDebug (String format) {
        __logDebug (format);
    }
    /*
    Self test of this class.
    */
    native static void __test (boolean verbose);
    public static void test (boolean verbose) {
        __test (verbose);
    }
}