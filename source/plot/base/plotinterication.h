#ifndef PLOTINTERICATION_H
#define PLOTINTERICATION_H

#include "plotelements.h"
#include <QObject>

class PlotInterication : public PlotElements
{
    Q_OBJECT;
public:
    PlotInterication(QWidget *parent = nullptr);

    /**
     * @brief setConnections 设置所有的信号槽连接
     */
    void setConnections();

    /**
     * @brief titleDoubleClick 双击了标题
     * @param event
     */
    void titleDoubleClick(QMouseEvent* event);

    /**
     * @brief axisLabelDoubleClick 双击了坐标轴
     * @param axis
     * @param part
     */
    void axisLabelDoubleClick(QCPAxis *axis, QCPAxis::SelectablePart part);

    /**
     * @brief legendDoubleClick 双击了图例区
     * @param legend
     * @param item
     */
    void legendDoubleClick(QCPLegend *legend, QCPAbstractLegendItem *item);

    /**
     * @brief selectionChanged 改变了选择区域
     */
    void selectionChanged();

    /**
     * @brief mousePress 按下了鼠标
     */
    void mousePress();

    /**
     * @brief mouseWheel 滚动了鼠标滚轮
     */
    void mouseWheel();

    /**
     * @brief contextMenuRequest 右键菜单
     * @param pos
     */
    void contextMenuRequest(QPoint pos);

    /**
     * @brief removeSelectedGraph 移除选中的图层
     */
    void removeSelectedGraph();

    /**
     * @brief moveLegend 移动图列
     */
    void moveLegend();

    /**
     * @brief editSelectedGraph 编辑选中的图层
     */
    void editSelectedGraph();

    /**
     * @brief output2Img 输出到图片
     */
    void output2Img();

    /**
     * @brief graphClicked 点击了图层
     * @param plottable
     * @param dataIndex
     */
    void graphClicked(QCPAbstractPlottable *plottable, int dataIndex);

protected:
    virtual void btn_moveCanvas_clicked(bool isChecked);

    virtual void btn_property_clicked();

    virtual void btn_fullView_clicked();

    virtual void btn_ratioView_clicked();

    virtual void btn_print_clicked();

};

#endif // PLOTINTERICATION_H
