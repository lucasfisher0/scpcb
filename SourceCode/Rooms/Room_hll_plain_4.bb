

Function UpdateEvent_hll_plain_4(e.Events)
	Local dist#, i%, temp%, pvt%, strtemp$, j%, k%

	Local p.Particles, n.NPCs, r.Rooms, e2.Events, it.Items, em.Emitters, sc.SecurityCams, sc2.SecurityCams

	Local CurrTrigger$ = ""

	Local x#, y#, z#

	Local angle#

	;[Block]
	If e\eventState < TimeInPosMilliSecs() Then
		If mainPlayer\currRoom <> e\room Then
			If Distance(EntityX(mainPlayer\collider),EntityZ(mainPlayer\collider),EntityX(e\room\obj),EntityZ(e\room\obj))<16.0 Then
				For n.NPCs = Each NPCs
					If n\npcType = NPCtype049 Then
						If n\state = 2 And EntityDistance(mainPlayer\collider,n\collider)>16.0 Then
							TFormVector(368, 528, 176, e\room\obj, 0)
							PositionEntity n\collider, EntityX(e\room\obj)+TFormedX(), TFormedY(), EntityZ(e\room\obj)+TFormedZ()
							DebugLog TFormedX()+", "+ TFormedY()+", "+ TFormedZ()
							ResetEntity n\collider
							n\pathStatus = 0
							n\state = 4
							n\state2 = 0
							RemoveEvent(e)
						EndIf
						Exit
					EndIf
				Next
			EndIf
		EndIf
		If e<>Null Then e\eventState = TimeInPosMilliSecs()+5000
	EndIf
	;[End Block]
End Function

