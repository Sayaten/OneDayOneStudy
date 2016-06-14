import utils, sys
from pydbg import *
from pydbg.defines import *

'''
BOOL WINAPI WriteFile(
    _In_    HANDLE hFile,
    _In_    LPCVIOD lpBuffer,
    _In_    DWORD nNumberOfBytesToWrite,
    _Out_opt_   LPDWORD lpNumberOfBytesWritten,
    _Inout_opt_ LPOVERLAPPED lpOverlapped
);
'''

dbg = pydbg()
isProcess = False

orgPattern = "TeFaL"
repPattern = "KwonTF"
processName = "notepad.exe"

def replaceString(dbg, args):
    buffer = dbg.read_process_memory(args[1], args[2])
    if orgPattern in buffer:
        print "[API Hooking] Before : %s" % buffer
        buffer = buffer.replace(orgPattern, repPattern)
        replace = dbg.write_process_memory(args[1], buffer)
        print "[API Hooking] After: %s" % dbg.read_process_memory(args[1], args[2])
    return DBG_CONTINUE
for(pid, name) in dbg.enumerate_processes():
    if name.lower() == processName:
        isProcess = True
        hooks = utils.hook_container()
        dbg.attach(pid)
        print "Saves a process handle in self.h_process of pid[%d]" % pid
        hookAddress = dbg.func_resolve_debuggee("kernel32.dll", "WriteFile")
        if hookAddress:
            hooks.add(dbg, hookAddress, 5, replaceString, None)
            print "sets a breakpoint at the designated address: 0x%08x" % hookAddress
            break
        else:
            print "[Error] : couldn't resolve hook address"
            sys.exit(-1)
if isProcess:
    print "waiting for occurring debugger event"
    dbg.run()
else:
    print "[Error] : There is no process [%s]" % processName
    sys.exit(-1)