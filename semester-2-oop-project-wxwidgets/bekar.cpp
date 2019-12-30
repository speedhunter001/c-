    Shapes * square_sh = new Square;
    vector<Point> v;
    v[0].set_coordinates(5,5);
    v[1].set_coordinates(10,5);
    v[2].set_coordinates(10,10);      //clockwise
    v[3].set_coordinates(5,10);
    all_shapes.push_back(square_sh);

for( Shapes * shape : all_shapes ){
        v = shape->get_points();
        if ( shape->get_shape_type() == "SQUARE" ) {
            //wxClientDC dc;
            dc.SetPen( wxPen( wxColor(230,0,0), 3 ) ); // black line, 3 pixels thick
            dc.DrawLine( v[0].get_x(), v[0].get_y(), v[1].get_x(), v[1].get_y() );
                      //dc.SetPen( wxPen( wxColor(0,250,255), 3 ) );           //for changing the colour of this llne specifically
            dc.DrawLine( v[1].get_x(), v[1].get_y(), v[2].get_x(), v[2].get_y() );
            // dc.SetPen( wxPen( wxColor(0,255,255), 3 ) );           //for changing the colour of this llne specifically
            dc.DrawLine(  v[2].get_x(), v[2].get_y(), v[3].get_x(), v[3].get_y() );
            // dc.SetPen( wxPen( wxColor(0,255,255), 3 ) );           //for changing the colour of this llne specifically
            dc.DrawLine(  v[3].get_x(), v[3].get_y(), v[0].get_x(), v[0].get_y() );                       
        }
    }
    //MSA CODE ENDS HERE