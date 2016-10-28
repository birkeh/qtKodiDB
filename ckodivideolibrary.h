#ifndef CKODIVIDEOLIBRARY_H
#define CKODIVIDEOLIBRARY_H


#include "cmyvideos.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStatusBar>

#include <QStandardItemModel>
#include <QTreeWidget>


class cKodiVideoLibrary
{
public:
	cKodiVideoLibrary(const QString& szFileName);
	~cKodiVideoLibrary();

	qint16				init();
	qint16				version();

	qint32				load();
	bool				art(const QString& szMediaType, const QString& szType, qint32 idMovie, qint32& artID, QString& szURL);

	void				fillVideoList(QStandardItemModel* lpModel);
	void				fillActorList(QTreeWidget* lpList, cMyVideos* lpVideos);
private:
	QSqlDatabase		m_db;
	QString				m_szFileName;
	bool				m_bConnected;
	qint16				m_iVersion;

	cMyVideosActorList	m_videosActorList;
	cMyVideosList		m_videosList;

	qint32				loadActors();
	qint32				loadVideos();
};

#endif // CKODIVIDEOLIBRARY_H
