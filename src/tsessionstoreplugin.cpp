/* Copyright (c) 2011-2012, AOYAMA Kazuharu
 * All rights reserved.
 *
 * This software may be used and distributed according to the terms of
 * the New BSD License, which is incorporated herein by reference.
 */

#include <TSessionStorePlugin>

/*!
  \class TSessionStorePlugin
  \brief The TSessionStorePlugin class provides an abstract base for
  custom TSessionStore plugins. Refer to 'How to Create Qt Plugins'
  in the Qt documentation.  
*/

/*!
  \fn virtual QStringList TSessionStorePlugin::keys() const
  Implement this function to return the list of valid keys,
  i.e.\ the session stores supported by this plugin.
*/

/*!
  \fn virtual TLogger *TSessionStorePlugin::create(const QString &key)
  Implement this function to create a session store matching the name specified
  by the given key.
*/



/*!
  \class TSessionStoreInterface
  \brief The TSessionStoreInterface class provides an interface to implement
  TSessionStore plugins.
*/
