#include "amf_http1_server.hpp"
#include "logger.hpp"

using namespace oai::amf::api;

void amf_http1_server::init(size_t thr) {
  auto opts = Pistache::Http::Endpoint::options().threads(thr);
  opts.flags(Pistache::Tcp::Options::ReuseAddr);
  opts.maxRequestSize(PISTACHE_SERVER_MAX_PAYLOAD);
  m_httpEndpoint->init(opts);

  m_aMFConfigurationApiImpl->init();
  m_individualSubscriptionDocumentApiImpl->init();
  m_individualSubscriptionDocumentApiImplEventExposure->init();
  m_individualUeContextDocumentApiImpl->init();
  m_n1N2IndividualSubscriptionDocumentApiImpl->init();
  m_n1N2MessageCollectionDocumentApiImpl->init();
  m_n1N2SubscriptionsCollectionForIndividualUEContextsDocumentApiImpl->init();
  m_nonUEN2MessageNotificationIndividualSubscriptionDocumentApiImpl->init();
  m_nonUEN2MessagesCollectionDocumentApiImpl->init();
  m_nonUEN2MessagesSubscriptionsCollectionDocumentApiImpl->init();
  m_subscriptionsCollectionDocumentApiImpl->init();
  m_subscriptionsCollectionDocumentApiImplEventExposure->init();
  m_n1MessageNotifyApiImpl->init();
  m_statusNotifyApiImpl->init();
  Logger::amf_server().debug("Initiate AMF Server Endpoints done!");
}

void amf_http1_server::start() {
  if (m_aMFConfigurationApiImpl != nullptr)
    Logger::amf_server().debug("AMF handler for AMFConfigurationApiImpl");

  if (m_individualSubscriptionDocumentApiImpl != nullptr)
    Logger::amf_server().debug(
        "AMF handler for IndividualSubscriptionDocumentApiImpl");
  if (m_individualSubscriptionDocumentApiImplEventExposure != nullptr)
    Logger::amf_server().debug(
        "AMF handler for IndividualSubscriptionDocumentApiImpl");
  if (m_individualUeContextDocumentApiImpl != nullptr)
    Logger::amf_server().debug(
        "AMF handler for IndividualUeContextDocumentApiImpl");
  if (m_n1N2IndividualSubscriptionDocumentApiImpl != nullptr)
    Logger::amf_server().debug(
        "AMF handler for N1N2IndividualSubscriptionDocumentApiImpl");
  if (m_n1N2MessageCollectionDocumentApiImpl != nullptr)
    Logger::amf_server().debug(
        "AMF handler for N1N2MessageCollectionDocumentApiImpl");
  if (m_n1N2SubscriptionsCollectionForIndividualUEContextsDocumentApiImpl !=
      nullptr)
    Logger::amf_server().debug(
        "AMF handler for "
        "N1N2SubscriptionsCollectionForIndividualUEContextsDocumentApiImpl");
  if (m_nonUEN2MessageNotificationIndividualSubscriptionDocumentApiImpl !=
      nullptr)
    Logger::amf_server().debug(
        "AMF handler for "
        "NonUEN2MessageNotificationIndividualSubscriptionDocumentApiImpl");
  if (m_nonUEN2MessagesCollectionDocumentApiImpl != nullptr)
    Logger::amf_server().debug(
        "AMF handler for NonUEN2MessagesCollectionDocumentApiImpl");
  if (m_nonUEN2MessagesSubscriptionsCollectionDocumentApiImpl != nullptr)
    Logger::amf_server().debug(
        "AMF handler for "
        "NonUEN2MessagesSubscriptionsCollectionDocumentApiImpl");
  if (m_subscriptionsCollectionDocumentApiImpl != nullptr)
    Logger::amf_server().debug(
        "AMF handler for SubscriptionsCollectionDocumentApiImpl");

  if (m_subscriptionsCollectionDocumentApiImplEventExposure != nullptr)
    Logger::amf_server().debug(
        "AMF handler for SubscriptionsCollectionDocumentApiImplEventExposure");

  if (m_n1MessageNotifyApiImpl != nullptr)
    Logger::amf_server().debug("AMF handler for N1MessageNotifyApiImpl");

  if (m_statusNotifyApiImpl != nullptr)
    Logger::amf_server().debug("AMF handler for StatusNotifyApiImpl");

  m_httpEndpoint->setHandler(m_router->handler());
  m_httpEndpoint->serveThreaded();
}
void amf_http1_server::shutdown() {
  m_httpEndpoint->shutdown();
}
