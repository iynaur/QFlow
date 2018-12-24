#include "QmlFlowPlugin.h"

#include <qqml.h>

#include "FlowGraph.h"
#include "FlowNode.h"
#include "FlowPort.h"
#include "FlowObject.h"
#include "FlowObjectStorage.h"
#include "FlowJsonStorage.h"
#include "FlowRequestRouter.h"

//#include "FlowTracer.h"
#include "FlowMonitor.h"
#include "FlowNodeMonitorInfo.h"
#include "FlowRestService.h"
#include "FlowRestConnection.h"
#include "FlowNodeServiceInfo.h"


void QmlFlowPlugin::registerTypes(const char *uri)
{
    // @uri com.chezgi.qmlflow

    qmlRegisterUncreatableType<FlowObject>("QmlFlow", 1, 0, "Object","Flow.Object is pure Virtual. use subclasses.");
    qmlRegisterUncreatableType<FlowPort>("QmlFlow", 1, 0, "Port","Use Directioned Ports.");
    qmlRegisterUncreatableType<FlowNodeMonitorInfo>("QmlFlow", 1, 0, "NodeMonitorInfo","Only usable as flownode.");
    qmlRegisterUncreatableType<FlowNodeServiceInfo>("QmlFlow", 1, 0, "NodeServiceInfo","Only usable as flownode.");
    qmlRegisterUncreatableType<FlowRestConnection>("QmlFlow", 1, 0, "RestConnection","Only for FlowService");

    qmlRegisterType<FlowGraph>("QmlFlow", 1, 0, "Graph");
    qmlRegisterType<FlowObjectStorage>("QmlFlow", 1, 0, "ObjectStorage");
    qmlRegisterType<FlowJsonStorage>("QmlFlow", 1, 0, "JsonStorage");
    qmlRegisterType<FlowMonitor>("QmlFlow", 1, 0, "Monitor");

    qmlRegisterType<FlowRestService>("QmlFlow", 1, 0, "Service");

    qmlRegisterType<FlowNode>("QmlFlow", 1, 0, "Node");

    qmlRegisterType<FlowRequestRouter>("QmlFlow", 1, 0, "RequestRouter");
    qmlRegisterType<FlowInPort>("QmlFlow", 1, 0, "InPort");
    qmlRegisterType<FlowOutPort>("QmlFlow", 1, 0, "OutPort");
}


