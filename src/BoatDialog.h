/******************************************************************************
 * $Id: boatdialog.h,v 1.8 2010/06/21 01:54:37 bdbcat Exp $
 *
 * Project:  OpenCPN
 * Purpose:  Weather Routing Plugin
 * Author:   Sean D'Epagnier
 *
 ***************************************************************************
 *   Copyright (C) 2013 by Sean D'Epagnier   *
 *   sean@depagnier.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
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
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.             *
 ***************************************************************************
 */

#ifndef _BOAT_DIALOG_H_
#define _BOAT_DIALOG_H_

#include <wx/fileconf.h>

#include "WeatherRoutingUI.h"

class weather_routing_pi;

class BoatDialog : public BoatDialogBase
{
public:

    BoatDialog( wxWindow *parent);
    ~BoatDialog();

    BoatSpeed m_Boat;

private:

    void OnMouseEventsPlot( wxMouseEvent& event );
    void OnPaintPlot( wxPaintEvent& event );
    void OnSizePlot( wxSizeEvent& event ) { m_PlotWindow->Refresh(); }
    void OnUpdatePlot( wxCommandEvent& event ) { m_PlotWindow->Refresh(); }
    void OnUpdatePlot( wxSpinEvent& event ) { m_PlotWindow->Refresh(); }
    void OnUpdateWindSpeed( wxSpinEvent& event );
    void OnOpen( wxCommandEvent& event );
    void OnSave( wxCommandEvent& event );
    void OnClose( wxCommandEvent& event ) { Hide(); }
    void OnRecompute( wxScrollEvent& event ) { Compute(); }
    void OnOptimizeTacking( wxCommandEvent& event );
    void OnResetOptimalTackingSpeed( wxCommandEvent& event );

    void Compute();
    void UpdateTrackingControls();
    void UpdateVMG();

    wxString m_default_boat_path;    
    double m_PlotScale;
    int m_MouseW;
};

#endif