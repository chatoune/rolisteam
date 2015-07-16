/***************************************************************************
    *      Copyright (C) 2010 by Renaud Guezennec                             *
    *                                                                         *
    *                                                                         *
    *   rolisteam is free software; you can redistribute it and/or modify     *
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
#ifndef VISUALITEM_H
#define VISUALITEM_H

#include <QGraphicsItem>

class NetworkMessageWriter;
class NetworkMessageReader;

/**
    * @brief abstract class which defines interface for all map items.
    * @todo Allows the modification of item's geometry, enable the selection.
    */
class VisualItem : public QGraphicsObject
{
        Q_OBJECT
public:
    enum ItemType{PATH,LINE,ELLISPE,CHARACTER,TEXT,RECT};
    VisualItem();
	VisualItem(QColor& penColor,bool b,QGraphicsItem * parent = 0);
    
	/**
	 * @brief setNewEnd
	 * @param nend
	 */
    virtual void setNewEnd(QPointF& nend)=0;
	/**
	 * @brief setPenColor
	 * @param penColor
	 */
    virtual void setPenColor(QColor& penColor);
	/**
	 * @brief writeData
	 * @param out
	 */
    virtual void writeData(QDataStream& out) const =0;
	/**
	 * @brief readData
	 * @param in
	 */
    virtual void readData(QDataStream& in)=0;
    
	/**
	 * @brief getType
	 * @return
	 */
    virtual VisualItem::ItemType getType()=0;
	/**
	 * @brief fillMessage
	 * @param msg
	 */
    virtual void fillMessage(NetworkMessageWriter* msg)=0;
	/**
	 * @brief readItem
	 * @param msg
	 */
    virtual void readItem(NetworkMessageReader* msg)=0;
	/**
	 * @brief setId
	 * @param id
	 */
    virtual void setId(QString id);
	/**
	 * @brief getId
	 * @return
	 */
    virtual QString getId();
	/**
	 * @brief setMapId
	 * @param id
	 */
    virtual void setMapId(QString id);
	/**
	 * @brief getMapId
	 * @return
	 */
    virtual QString getMapId();
	/**
	 * @brief setEditableItem
	 */
	virtual void setEditableItem(bool);


	friend QDataStream& operator<<(QDataStream& os,const VisualItem&);
	friend QDataStream& operator>>(QDataStream& is,VisualItem&);
public slots:
    void sendPositionMsg();
    void readPositionMsg(NetworkMessageReader* msg);
    
protected:
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    virtual void mousePressEvent ( QGraphicsSceneMouseEvent * event );
    virtual void mouseMoveEvent ( QGraphicsSceneMouseEvent * event );
    void init();
    
    
    QColor m_color;
    ItemType m_type;
    QString m_id;
    QString m_mapId;
	bool m_editable;
};

#endif // VISUALITEM_H
