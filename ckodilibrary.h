#ifndef CKODILIBRARY_H
#define CKODILIBRARY_H


#include "ckodivideolibrary.h"
#include "ckoditextureslibrary.h"

//#include "cimage.h"

#include <QStatusBar>
#include <QStandardItemModel>

#include <QSplashScreen>


class cImage;
class cImageList;

class cKodiLibrary
{
public:
	cKodiLibrary(QStatusBar* lpMainWindowStatusBar, const QString& szPath);
	cKodiLibrary(QSplashScreen* lpSplashScreen, const QString& szPath);
	~cKodiLibrary();

	bool					init();

	cKodiVideoLibrary*		videoLibrary();
	cKodiTexturesLibrary*	texturesLibrary();
	cImageList*				imageList();
private:
	QStatusBar*				m_lpMainWindowStatusBar;
	QSplashScreen*			m_lpSplashScreen;
	cKodiVideoLibrary*		m_lpKodiVideoLibrary;
	cKodiTexturesLibrary*	m_lpKodiTexturesLibrary;
	cImageList*				m_lpImageList;
	QString					m_szPath;

	QString					m_szAddons;
	QString					m_szADSP;
	QString					m_szEpg;
	QString					m_szMyMusic;
	QString					m_szMyVideos;
	QString					m_szTextures;
	QString					m_szTV;
	QString					m_szViewModes;

	QString					findFile(const QString& szPath, const QString& szFile);
};

#endif // CKODILIBRARY_H
