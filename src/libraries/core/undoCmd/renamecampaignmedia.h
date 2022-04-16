/***************************************************************************
 *	Copyright (C) 2021 by Renaud Guezennec                               *
 *   http://www.rolisteam.org/contact                                      *
 *                                                                         *
 *   This software is free software; you can redistribute it and/or modify *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef RENAMECAMPAIGNMEDIA_H
#define RENAMECAMPAIGNMEDIA_H

#include <QPointer>
#include <QUndoCommand>
namespace campaign
{
class MediaNode;
class MediaModel;
class Campaign;
} // namespace campaign
class RenameCampaignMedia : public QUndoCommand
{
public:
    RenameCampaignMedia(campaign::MediaNode* mediaNode, const QString& newPath, const QString& oldPath,
                        campaign::MediaModel* model, campaign::Campaign* campaign);

    void redo() override;
    void undo() override;

private:
    QPointer<campaign::MediaModel> m_model;
    QPointer<campaign::MediaNode> m_media;
    QString m_newPath;
    QString m_oldPath;
    QPointer<campaign::Campaign> m_campaign;
};

#endif // RENAMECAMPAIGNMEDIA_H
