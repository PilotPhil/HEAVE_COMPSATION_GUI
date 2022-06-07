#include "plotinterication.h"

#include "setaxis.h"
#include "setprint.h"
#include "setcurve.h"
#include "setplot.h"

PlotInterication::PlotInterication(QWidget *parent):PlotElements(parent)
{
    canvas->setInteraction(QCP::iSelectAxes,true);
    canvas->setInteraction(QCP::iSelectLegend,true);
    canvas->setInteraction(QCP::iSelectPlottables,true);

    setConnections();
}

void PlotInterication::setConnections()
{
    connect(_title,&QCPTextElement::doubleClicked,this,&PlotInterication::titleDoubleClick);
    connect(canvas, &QCustomPlot::axisDoubleClick, this, &PlotInterication::axisLabelDoubleClick);
    connect(canvas, &QCustomPlot::selectionChangedByUser, this, &PlotInterication::selectionChanged);
    connect(canvas, &QCustomPlot::mousePress, this, &PlotInterication::mousePress);
    connect(canvas, &QCustomPlot::mouseWheel, this, &PlotInterication::mouseWheel);
    connect(canvas, &QCustomPlot::selectionChangedByUser, this, &PlotInterication::selectionChanged);
    connect(canvas->xAxis, SIGNAL(rangeChanged(QCPRange)), canvas->xAxis2, SLOT(setRange(QCPRange)));
    connect(canvas->yAxis, SIGNAL(rangeChanged(QCPRange)), canvas->yAxis2, SLOT(setRange(QCPRange)));
    connect(canvas, &QCustomPlot::plottableDoubleClick, this, &PlotInterication::graphClicked);
    connect(canvas, &QCustomPlot::customContextMenuRequested, this, &PlotInterication::contextMenuRequest);
    canvas->setContextMenuPolicy(Qt::CustomContextMenu);
}

void PlotInterication::titleDoubleClick(QMouseEvent *event)
{
    Q_UNUSED(event);
    if (QCPTextElement *title = qobject_cast<QCPTextElement*>(sender()))
    {
      // Set the plot title by double clicking on it
      bool ok;
      QString newTitle = QInputDialog::getText(this,QString::fromLocal8Bit("修改"),QString::fromLocal8Bit("新标题名:"), QLineEdit::Normal, title->text(), &ok);
      if (ok)
      {
        title->setText(newTitle);
        canvas->replot();
      }
    }
}

void PlotInterication::axisLabelDoubleClick(QCPAxis *axis, QCPAxis::SelectablePart part)
{
    // Set an axis label by double clicking on it
    if (part == QCPAxis::spAxisLabel) // only react when the actual axis label is clicked, not tick label or axis backbone
    {
      AxisProp a_p;

      a_p.label=axis->label();
      a_p.range.min=axis->range().lower;
      a_p.range.max=axis->range().upper;

      SetAxis dialog(a_p,this);

      auto flag=dialog.exec();

      if(flag==QDialog::Accepted)
      {
        setAxis(dialog.getAxisProp(),axis);
      }
    }
}

void PlotInterication::legendDoubleClick(QCPLegend *legend, QCPAbstractLegendItem *item)
{
    // Rename a graph by double clicking on its legend item
    Q_UNUSED(legend)
    if (item) // only react if item was clicked (user could have clicked on border padding of legend where there is no item, then item is 0)
    {
      QCPPlottableLegendItem *plItem = qobject_cast<QCPPlottableLegendItem*>(item);
      bool ok;
      QString newName = QInputDialog::getText(this,QString::fromLocal8Bit("编辑"), QString::fromLocal8Bit("曲线名:"), QLineEdit::Normal, plItem->plottable()->name(), &ok);
      if (ok)
      {
        plItem->plottable()->setName(newName);
        canvas->replot();
      }
    }
}

void PlotInterication::selectionChanged()
{
    /*
       normally, axis base line, axis tick labels and axis labels are selectable separately, but we want
       the user only to be able to select the axis as a whole, so we tie the selected states of the tick labels
       and the axis base line together. However, the axis label shall be selectable individually.

       The selection state of the left and right axes shall be synchronized as well as the state of the
       bottom and top axes.

       Further, we want to synchronize the selection of the graphs with the selection state of the respective
       legend item belonging to that graph. So the user can select a graph by either clicking on the graph itself
       or on its legend item.
      */

      // make top and bottom axes be selected synchronously, and handle axis and tick labels as one selectable object:
      if (canvas->xAxis->selectedParts().testFlag(QCPAxis::spAxis) || canvas->xAxis->selectedParts().testFlag(QCPAxis::spTickLabels) ||
          canvas->xAxis2->selectedParts().testFlag(QCPAxis::spAxis) || canvas->xAxis2->selectedParts().testFlag(QCPAxis::spTickLabels))
      {
        canvas->xAxis2->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
        canvas->xAxis->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
      }

      // make left and right axes be selected synchronously, and handle axis and tick labels as one selectable object:
      if (canvas->yAxis->selectedParts().testFlag(QCPAxis::spAxis) || canvas->yAxis->selectedParts().testFlag(QCPAxis::spTickLabels) ||
          canvas->yAxis2->selectedParts().testFlag(QCPAxis::spAxis) || canvas->yAxis2->selectedParts().testFlag(QCPAxis::spTickLabels))
      {
        canvas->yAxis2->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
        canvas->yAxis->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
      }

      // synchronize selection of graphs with selection of corresponding legend items:
      for (int i=0; i<canvas->graphCount(); ++i)
      {
        QCPGraph *graph = canvas->graph(i);
        QCPPlottableLegendItem *item = canvas->legend->itemWithPlottable(graph);
        if (item->selected() || graph->selected())
        {
          item->setSelected(true);
          graph->setSelection(QCPDataSelection(graph->data()->dataRange()));
        }
      }
}

void PlotInterication::mousePress()
{
    // if an axis is selected, only allow the direction of that axis to be dragged
    // if no axis is selected, both directions may be dragged

    if (canvas->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
      canvas->axisRect()->setRangeDrag(canvas->xAxis->orientation());
    else if (canvas->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
      canvas->axisRect()->setRangeDrag(canvas->yAxis->orientation());
    else
      canvas->axisRect()->setRangeDrag(Qt::Horizontal|Qt::Vertical);
}

void PlotInterication::mouseWheel()
{
    // if an axis is selected, only allow the direction of that axis to be zoomed
    // if no axis is selected, both directions may be zoomed

    if (canvas->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
      canvas->axisRect()->setRangeZoom(canvas->xAxis->orientation());
    else if (canvas->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
      canvas->axisRect()->setRangeZoom(canvas->yAxis->orientation());
    else
        canvas->axisRect()->setRangeZoom(Qt::Horizontal|Qt::Vertical);
}

void PlotInterication::contextMenuRequest(QPoint pos)
{
    QMenu *menu = new QMenu(this);
      menu->setAttribute(Qt::WA_DeleteOnClose);

      if (canvas->legend->selectTest(pos, false) >= 0) // context menu on legend requested
      {
        menu->addAction(QString::fromLocal8Bit("移到左上"), this, &PlotInterication::moveLegend)->setData((int)(Qt::AlignTop|Qt::AlignLeft));
        menu->addAction(QString::fromLocal8Bit("移到上中"), this, &PlotInterication::moveLegend)->setData((int)(Qt::AlignTop|Qt::AlignHCenter));
        menu->addAction(QString::fromLocal8Bit("移到右上"), this, &PlotInterication::moveLegend)->setData((int)(Qt::AlignTop|Qt::AlignRight));
        menu->addAction(QString::fromLocal8Bit("移到右下"), this, &PlotInterication::moveLegend)->setData((int)(Qt::AlignBottom|Qt::AlignRight));
        menu->addAction(QString::fromLocal8Bit("移到左下"), this, &PlotInterication::moveLegend)->setData((int)(Qt::AlignBottom|Qt::AlignLeft));
      }
      else // general context menu on graphs requested
      {
          menu->addAction(QString::fromLocal8Bit("显示主坐标轴"), this, [&]()
          {
              if(canvas->xAxis->visible()==true)
                  showMainAxis(false);
              else
                  showMainAxis(true);
          });

          menu->addAction(QString::fromLocal8Bit("显示副坐标轴"), this, [&]()
          {
              if(canvas->xAxis2->visible()==true)
                  showSubAxis(false);
              else
                  showSubAxis(true);
          });

          menu->addAction(QString::fromLocal8Bit("显示图例"), this, [&]()
          {
              if(canvas->legend->visible()==true)
                  showLegend(false);
              else
                  showLegend(true);
          });

          menu->addAction(QString::fromLocal8Bit("移除标题"), this, &PlotInterication::removeTitle);
          menu->addAction(QString::fromLocal8Bit("添加标题"), this, &PlotInterication::addDefaultTitle);

    //    menu->addAction(QString::fromLocal8Bit("添加随机曲线（test）"), this,` &PlotInterication::addRandomGraph);
        if (canvas->selectedGraphs().size() > 0)
        {
            menu->addAction(QString::fromLocal8Bit("编辑选中的曲线"), this, &PlotInterication::editSelectedGraph);
            menu->addAction(QString::fromLocal8Bit("移除选中的曲线"), this, &PlotInterication::removeSelectedGraph);
        }
        if (canvas->graphCount() > 0)
        {
            menu->addAction(QString::fromLocal8Bit("最佳视图"), this, &PlotInterication::adjustAxisFullCanvas);
            menu->addAction(QString::fromLocal8Bit("等比视图"), this, &PlotInterication::adjustAxisKeepRatio);
            menu->addAction(QString::fromLocal8Bit("移除所有曲线"), this, &PlotInterication::removeAllGraph);
            menu->addAction(QString::fromLocal8Bit("输出到图片"), this, &PlotInterication::output2Img);
        }



      }

      menu->popup(canvas->mapToGlobal(pos));
}

void PlotInterication::removeSelectedGraph()
{
    if (canvas->selectedGraphs().size() > 0)
    {
      removeGraph(canvas->selectedGraphs().first());
    }
    canvas->replot();
}

void PlotInterication::moveLegend()
{
    if (QAction* contextAction = qobject_cast<QAction*>(sender())) // make sure this slot is really called by a context menu action, so it carries the data we need
    {
      bool ok;
      int dataInt = contextAction->data().toInt(&ok);
      if (ok)
      {
        canvas->axisRect()->insetLayout()->setInsetAlignment(0, (Qt::Alignment)dataInt);
        canvas->replot();
      }
    }
}

void PlotInterication::editSelectedGraph()
{
    if (canvas->selectedGraphs().size() > 0)
    {
        auto g=canvas->selectedGraphs().first();

        if(g==nullptr)
            return;

        CurveProp c_p(g->name(),g->pen(),g->lineStyle(),g->scatterStyle());

        SetCurve dialog(c_p);

        auto flag=dialog.exec();

        if(flag==QDialog::Accepted)
        {
            auto res_p=dialog.getCurveProp();

            setCurve(g,res_p);
        }
    }
}

void PlotInterication::output2Img()
{
    PrintProp p;
    SetPrint dialog(p,this);
    auto flag=dialog.exec();

    if(flag==QDialog::Accepted)
    {
        print(dialog.getPrintProp());
    }
}

void PlotInterication::graphClicked(QCPAbstractPlottable *plottable, int dataIndex)
{
    // since we know we only have QCPGraphs in the plot, we can immediately access interface1D()
    // usually it's better to first check whether interface1D() returns non-zero, and only then use it.
    double dataValue = plottable->interface1D()->dataMainValue(dataIndex);
    QString message = QString("Clicked on graph '%1' at data point #%2 with value %3.").arg(plottable->name()).arg(dataIndex).arg(dataValue);
    //  ui->statusBar->showMessage(message, 2500);
}


void PlotInterication::btn_moveCanvas_clicked(bool isChecked)
{
    auto enableInteraction=[&](bool isEnable)
    {
        canvas->setInteraction(QCP::iRangeDrag,isEnable);
        canvas->setInteraction(QCP::iRangeZoom,isEnable);
    };

    enableInteraction(isChecked);
}

void PlotInterication::btn_property_clicked()
{
    PlotProp plotProp;

    //title
    plotProp.titleProp=TitleProp(_title->text(),_title->font());
    canvas->plotLayout()->elementCount()>1?plotProp.showTitle=true:plotProp.showTitle=false;

    //axis
    plotProp.xaxisProp=AxisProp(canvas->xAxis->label(),RangeProp(canvas->xAxis->range().lower,canvas->xAxis->range().upper));
    plotProp.yaxisProp=AxisProp(canvas->yAxis->label(),RangeProp(canvas->yAxis->range().lower,canvas->yAxis->range().upper));
    plotProp.showMainAxis=canvas->xAxis->visible();
    plotProp.showSubAxis=canvas->xAxis2->visible();

    //legend
    plotProp.showLegend=canvas->legend->visible();

    //curves
    auto c=canvas->graphCount();
    for(int i=0;i<c;i++)
    {
        auto g=canvas->graph(i);

        if(g==nullptr)
            continue;

        CurveProp p(g->name(),
                    g->pen(),
                    g->lineStyle(),
                    g->scatterStyle());

        plotProp.curveProps.append(p);
    }

    setPlot dialog(plotProp,this);

    auto flag=dialog.exec();

    if(flag==QDialog::Accepted)
    {
        auto prop=dialog.getPlotProp();

        if(prop.showTitle)
            setTitle(prop.titleProp);
        else
            removeTitle();

        showMainAxis(prop.showMainAxis);
        showSubAxis(prop.showSubAxis);
        setAxis(prop.xaxisProp,axisPosition::atDown);
        setAxis(prop.yaxisProp,axisPosition::atLeft);

        showLegend(prop.showLegend);

        for(int i=0;i<prop.curveProps.length();i++)
        {
            setCurve(i,prop.curveProps[i]);
        }
    }
}

void PlotInterication::btn_fullView_clicked()
{
    adjustAxisFullCanvas();
}

void PlotInterication::btn_ratioView_clicked()
{
    adjustAxisKeepRatio();
}

void PlotInterication::btn_print_clicked()
{
    output2Img();
}
