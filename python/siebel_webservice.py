#!/usr/bin/env python
#-*- coding:utf-8 -*-

import sys, httplib

SoapMessage = """<soapenv:Envelope xmlns:soapenv="http://schemas.xmlsoap.org/soap/envelope/" xmlns:sync="http://siebel.com/sync/">
<soapenv:Header>
     <UsernameToken xmlns="http://siebel.com/webservices">SADMIN</UsernameToken>
     <PasswordText xmlns="http://siebel.com/webservices">SSbio</PasswordText>
     <SessionType xmlns="http://siebel.com/webservices">None</SessionType>
</soapenv:Header>
   <soapenv:Body>
      <sync:UpdateRecord>
         <HospitalInfo>
         &lt;Hospital&gt;&lt;SiebelId&gt;123568&lt;/SiebelId&gt;&lt;VeevaId&gt;108007&lt;/VeevaId&gt;&lt;Vid&gt;8765908&lt;/Vid&gt;&lt;Code&gt;Hs0101001&lt;/Code&gt;&lt;Name&gt;北京市第一人民医院&lt;/Name&gt;&lt;Alias&gt;北京897医院&lt;/Alias&gt;&lt;Deleted&gt;0&lt;/Deleted&gt;&lt;Province&gt;北京市&lt;/Province&gt;&lt;Municipality&gt;北京市&lt;/Municipality&gt;&lt;County&gt;海淀区&lt;/County&gt;&lt;Address&gt;朝阳门北大街01号&lt;/Address&gt;&lt;HosClassification&gt;公立医院&lt;/HosClassification&gt;&lt;HosCategory&gt;大医院&lt;/HosCategory&gt;&lt;HosLevel&gt;三甲&lt;/HosLevel&gt;&lt;HosAttribute&gt;外科&lt;/HosAttribute&gt;&lt;Beds&gt;15&lt;/Beds&gt;&lt;DailyPatientVisits&gt;879&lt;/DailyPatientVisits&gt;&lt;DialyzerNum&gt;666&lt;/DialyzerNum&gt;&lt;MobilePhone&gt;15698764536&lt;/MobilePhone&gt;&lt;PostCode&gt;100000&lt;/PostCode&gt;&lt;Url&gt;www.baidu.com&lt;/Url&gt;&lt;Memo&gt;测试数据&lt;/Memo&gt;&lt;/Hospital&gt;
         </HospitalInfo>
      </sync:UpdateRecord>
   </soapenv:Body>
</soapenv:Envelope>
"""
#SoapMessage = SM_TEMPLATE

webservice = httplib.HTTP("172.16.1.251")
webservice.putrequest("POST", "/eai_chs/start.swe?SWEExtSource=WebService&SWEExtCmd=Execute&WSSOAP=1")
webservice.putheader("Host", "172.16.1.251")
webservice.putheader("User-Agent", "Python post")
webservice.putheader("Content-type", "text/xml; charset=\"UTF-8\"")
webservice.putheader("Content-length", "%d" % len(SoapMessage))
#webservice.putheader("SOAPAction", "rpc/http://siebel.com/sync/:CreateRecord")
webservice.endheaders()
webservice.send(SoapMessage)

print webservice.getreply()

resmessage = webservice.getfile().read()
ResponseMessage = resmessage[resmessage.find('<ResponseMessage>') +17 :resmessage.find('</ResponseMessage>')]
ResponseCode = resmessage[resmessage.find('<ResponseCode>') +14 :resmessage.find('</ResponseCode>')]
ResponseVeevaId = resmessage[resmessage.find('<ResponseVeevaId>') +17 :resmessage.find('</ResponseVeevaId>')]
ResponseSiebelId = resmessage[resmessage.find('<ResponseSiebelId>') +18 :resmessage.find('</ResponseSiebelId>')]
OutXml = resmessage[resmessage.find('<OutXml>') +1 :resmessage.find('</OutXml>')]
OutXml = OutXml.replace('<','<').replace('>','>')

print 'ResponseMessage = ',ResponseMessage
print 'ResponseCode = ',ResponseCode
print 'ResponseVeevaId = ',ResponseVeevaId
#print 'ResponseSiebelId = ',ResponseSiebelId
print 'OutXml = ',OutXml