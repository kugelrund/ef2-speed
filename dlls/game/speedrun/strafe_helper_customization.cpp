#include "strafe_helper/strafe_helper_customization.h"

#include "../g_local.h"
#include "../gamecmds.h"

#include <cmath>


extern "C" {

void shc_drawFilledRectangle(float x, float y, float w, float h,
                             const shc_ElementId element_id)
{
	if (std::isnan(x) || std::isnan(w) || !cg_drawStrafeHelper->integer) {
		x = 0.0f;
		y = 0.0f;
		w = 0.0f;
		h = 0.0f;
	}
	// "1" as fifth argument to rect ensures that the widget is properly stretched like the whole menu is
	switch (element_id) {
		case shc_ElementId_AcceleratingAngles:
			G_SendCommandToPlayer( &g_entities[0], va("globalwidgetcommand strafehelper_accelerating rect %f %f %f %f 1\n", x, y, w, h));
			break;
		case shc_ElementId_OptimalAngle:
			G_SendCommandToPlayer( &g_entities[0], va("globalwidgetcommand strafehelper_optimal rect %f %f %f %f 1\n", x, y, w, h) );
			break;
		case shc_ElementId_CenterMarker:
			G_SendCommandToPlayer( &g_entities[0], va("globalwidgetcommand strafehelper_centermarker rect %f %f %f %f 1\n", x, y, w, h) );
			break;
	}
}

void shc_drawString(const float x, const float y, const char* string,
                    const float scale, const shc_ElementId element_id)
{
	if (!cg_drawStrafeHelper->integer) {
		string = "";
	}
	switch (element_id) {
		case shc_ElementId_SpeedText:
			G_SendCommandToPlayer( &g_entities[0], va("globalwidgetcommand strafehelper_speed title %s\n", string) );
			break;
	}
}

} // extern "C"
