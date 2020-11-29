
include(cpfMiscUtilities)

# ----------------------------------------------------------------------------------
#
# requirementsList:		A list in the form "TARGET <target> <version> TARGET ... " 
#
function( checkVersionRequirements requirementsList )

	cpfGetKeywordValueLists( dependencyVariables TARGET "" "${ARGN}" dependency )
	foreach(variable ${dependencyVariables})
		set(values ${${variable}})
		devMessage("${values}")
	endforach()


endfunction()


