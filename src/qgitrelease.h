#ifndef QGITRELEASE_H
#define QGITRELEASE_H

#include <QObject>

#include "qgitasset.h"

class QGitRelease : QObject
{
public:
    enum RequestError {
        NoError,
        NetworkError,
        NoRelease
    };

    QGitRelease(QObject *parent = nullptr);
    void get(const QString &owner, const QString &repo, int number = 0);

    QString name() const;
    QString tagName() const;
    QString body() const;

    QUrl url() const;
    QUrl tarUrl() const;
    QUrl zipUrl() const;

    QList<QGitAsset> assets() const;
    QDateTime createdAt() const;
    QDateTime publishedAt() const;

    int id() const;
    bool draft() const;
    bool prerelease() const;
    RequestError error() const;
    QString errorName() const;

private:
    QString m_name;
    QString m_tagName;
    QString m_body;

    QUrl m_url;
    QUrl m_tarUrl;
    QUrl m_zipUrl;
    QList<QGitAsset> m_assets;

    QDateTime m_createdAt;
    QDateTime m_publishedAt;

    int m_id;
    bool m_draft;
    bool m_prerelease;
    RequestError m_error;
    QString m_errorName;
};

#endif // QGITRELEASE_H
