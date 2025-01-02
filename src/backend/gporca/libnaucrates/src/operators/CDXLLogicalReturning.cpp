//---------------------------------------------------------------------------
//
//	@filename:
//		CDXLLogicalReturning.cpp
//
//	@doc:
//		Implementation of DXL logical returning operator
//---------------------------------------------------------------------------

#include "naucrates/dxl/operators/CDXLLogicalReturning.h"

#include "gpos/string/CWStringDynamic.h"

#include "naucrates/dxl/CDXLUtils.h"
#include "naucrates/dxl/operators/CDXLNode.h"
#include "naucrates/dxl/operators/CDXLOperator.h"
#include "naucrates/dxl/xml/CXMLSerializer.h"

using namespace gpos;
using namespace gpdxl;

//---------------------------------------------------------------------------
//	@function:
//		CDXLLogicalReturning::CDXLLogicalReturning
//
//	@doc:
//		Ctor
//
//---------------------------------------------------------------------------
CDXLLogicalReturning::CDXLLogicalReturning(CMemoryPool *mp) : CDXLLogical(mp)
{
}

//---------------------------------------------------------------------------
//	@function:
//		CDXLLogicalReturning::~CDXLLogicalReturning
//
//	@doc:
//		Dtor
//
//---------------------------------------------------------------------------
CDXLLogicalReturning::~CDXLLogicalReturning()
{
}

//---------------------------------------------------------------------------
//	@function:
//		CDXLLogicalReturning::GetDXLOperator
//
//	@doc:
//		Operator type
//
//---------------------------------------------------------------------------
Edxlopid
CDXLLogicalReturning::GetDXLOperator() const
{
	return EdxlopLogicalReturning;
}

//---------------------------------------------------------------------------
//	@function:
//		CDXLLogicalReturning::GetOpNameStr
//
//	@doc:
//		Operator name
//
//---------------------------------------------------------------------------
const CWStringConst *
CDXLLogicalReturning::GetOpNameStr() const
{
	return CDXLTokens::GetDXLTokenStr(EdxltokenLogicalReturning);
}

//---------------------------------------------------------------------------
//	@function:
//		CDXLLogicalReturning::SerializeToDXL
//
//	@doc:
//		Serialize function descriptor in DXL format
//
//---------------------------------------------------------------------------
void
CDXLLogicalReturning::SerializeToDXL(CXMLSerializer *xml_serializer,
									 const CDXLNode *node) const
{
	const CWStringConst *element_name = GetOpNameStr();
	xml_serializer->OpenElement(
		CDXLTokens::GetDXLTokenStr(EdxltokenNamespacePrefix), element_name);

	// serialize children
	node->SerializeChildrenToDXL(xml_serializer);

	xml_serializer->CloseElement(
		CDXLTokens::GetDXLTokenStr(EdxltokenNamespacePrefix), element_name);
}

#ifdef GPOS_DEBUG
//---------------------------------------------------------------------------
//	@function:
//		CDXLLogicalReturning::AssertValid
//
//	@doc:
//		Checks whether operator node is well-structured
//
//---------------------------------------------------------------------------
void
CDXLLogicalReturning::AssertValid(const CDXLNode *node,
								  BOOL validate_children) const
{
	const ULONG num_of_child = node->Arity();
	GPOS_ASSERT(num_of_child == 1);

	if (validate_children)
	{
		CDXLNode *child_dxlnode = (*node)[0];

		if (validate_children)
		{
			child_dxlnode->GetOperator()->AssertValid(child_dxlnode,
													  validate_children);
		}
	}
}

#endif	// GPOS_DEBUG


// EOF
