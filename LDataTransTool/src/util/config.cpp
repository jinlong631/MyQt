﻿#include "config.h"

#include "util.h"

#include <QString>
#include <QStringList>
#include <QDebug>

Config::Config()
{
    m_pUtil = new Util;
}

Config::~Config()
{
    destroy();
}

void Config::setAppPath(const QString &path)
{
    m_pUtil->setConfigPath(path);
}

bool Config::loadDefaultInfo()
{
    return m_pUtil->checkConfigFile("data/config.ini");
}

bool Config::emptyConfigFile()
{
    return m_pUtil->emptyConfigFile("data/config.ini");
}

bool Config::writeInitfile(const QString &group, const QString &key,
                           const QVariant &value)
{
    QString path = m_pUtil->getConfigPath()+"/data/config.ini";
    return m_pUtil->writeInit(path,group,key,value);
}

bool Config::writeInitfile(const QString &group, const QVariantMap &params)
{
    QString path = m_pUtil->getConfigPath()+"/data/config.ini";
    for (QVariantMap::const_iterator i = params.constBegin();
         i != params.constEnd();i++)
    {
        if ( !m_pUtil->writeInit(path,group,i.key(),i.value()))
            return false;
    }
    return true;
}

void Config::destroy()
{
    delete m_pUtil;
    m_pUtil = NULL;
}

QString Config::getAppPath() const
{
    return m_pUtil->getConfigPath();
}

QString Config::getDatabaseType() const
{
    return m_pUtil->getString("database.type");
}

QString Config::getDatabaseHost() const
{
    return m_pUtil->getString("database.host");
}

QString Config::getDatabaseName() const
{
    return m_pUtil->getString("database.database_name");
}

QString Config::getDatabaseUsername() const
{
    return m_pUtil->getString("database.username");
}

QString Config::getDatabasePassword() const
{
    return m_pUtil->getString("database.password");
}

QString Config::getDatabaseTestOnBorrowSql() const
{
    return m_pUtil->getString("database.test_on_borrow");
}

bool Config::getDatabaseTestOnBorrow() const
{
    return m_pUtil->getBool("database.test_on_borrow");
}

int Config::getDatabaseMaxWaitTime() const
{
    return m_pUtil->getInt("database.max_wait_time");
}

int Config::getDatabaseMaxConnectionCount() const
{
    return m_pUtil->getInt("database.max_connection_count");
}

int Config::getDatabasePort() const
{
    return m_pUtil->getInt("database.port");
}

bool Config::isDatabaseDebug() const
{
    return m_pUtil->getBool("database.debug");
}

QString Config::getWifiServerIp() const
{
    return m_pUtil->getString("wifi.tcp_ip");
}

int Config::getWifiServerPort() const
{
    return m_pUtil->getInt("wifi.tcp_port");
}

bool Config::isRconnect() const
{
    return m_pUtil->getBool ("wifi.r_connect");
}


void Config::conTest()
{
    qDebug()<<"getAppPath:"<<getAppPath();
    qDebug()<<"getDatabaseType:"<<getDatabaseType();
    qDebug()<<"getDatabaseHost:"<<getDatabaseHost();
    qDebug()<<"getDatabaseName:"<<getDatabaseName();
    qDebug()<<"getDatabaseUsername:"<<getDatabaseUsername();
    qDebug()<<"getDatabasePassword:"<<getDatabasePassword();
    qDebug()<<"getDatabaseTestOnBorrowSql:"<<getDatabaseTestOnBorrowSql();
    qDebug()<<"getDatabaseTestOnBorrow:"<<getDatabaseTestOnBorrow();
    qDebug()<<"getDatabaseMaxWaitTime:"<<getDatabaseMaxWaitTime();
    qDebug()<<"getDatabaseMaxConnectionCount:"<<getDatabaseMaxConnectionCount();
    qDebug()<<"getDatabasePort:"<<getDatabasePort();
    qDebug()<<"isDatabaseDebug:"<<isDatabaseDebug();
    qDebug()<<"getWifiServerIp():"<<getWifiServerIp();
    qDebug()<<"getWifiServerPort():"<<getWifiServerPort();

}
