#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H


#include <QString>
#include <QStringList>

class Environment
{
private:
	QStringList envs;
	QStringList values;
public:
	Environment();

	void readEnvList (void);
	QStringList getEnvs (void);
	QStringList getValues (void);
	void addEnv (QString env, QString value);
	void removeEnv (QString env);

};

#endif // ENVIRONMENT_H
