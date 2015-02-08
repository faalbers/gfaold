import os

# BASE ENVIRONMENT
# Environment that is platform agnostic
baseEnv = Environment()

platform    = baseEnv['PLATFORM']
debug       = False

# platform and user specific
if platform == 'posix':
    user = os.environ['USER']
    baseEnv.Append(CCFLAGS = [
        '-D_POSIX'
        #,'-std=c++0x'
        ,'-std=c++11'
        ,'-pedantic-errors'
        ,'-Wall'
        ,'-Wextra'
        ,'-Wuninitialized'
        ])
    if user == 'afrank':
        baseEnv.Replace(CXX = '/dist/d2sets/fedora-11-x86_64/tools-base-03-python/bin/g++')
    elif user == 'frank':
        pass
elif platform == 'win32':
    user = os.environ['USERNAME']
    baseEnv.Append(ENV = {'PATH' : os.environ['PATH']})
    baseEnv.Append(ENV = {'LIB' : os.environ.get('LIB')})
    baseEnv.Append(ENV = {'INCLUDE' : os.environ.get('INCLUDE')})
    baseEnv.Append(CCFLAGS = [
        '-D_WIN32'
        ,'-DGFA_BUILDING_DLL'
        #,'/W4'
        #,'/Wall'
        #,'/WX'
        #,'/Za'
        ,'/EHsc'
        ])
elif platform == 'darwin':
    baseEnv.Append(CCFLAGS = [
        '-D_DARWIN'])

# DIST SCTRUCTURE and flags
if debug:
    baseEnv['BUILDKIND'] = 'debug'
    baseEnv.Append(CCFLAGS = ['-fno-inline', '-O0', '-g3'])
else:
    baseEnv['BUILDKIND'] = 'opt'
    if platform != 'win32':
        baseEnv.Append(CCFLAGS = ['-O'])
distPath = '#/inst/%s/%s' % (baseEnv['PLATFORM'], baseEnv['BUILDKIND'])
baseEnv['DISTPATH'] = distPath

Export('baseEnv')

SConscript('SConscript')

