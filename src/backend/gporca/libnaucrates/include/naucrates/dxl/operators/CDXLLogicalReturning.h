//---------------------------------------------------------------------------
//
//	@filename:
//		CDXLLogicalReturning.h
//
//	@doc:
//		Class for representing DXL logical returning list operators
//
//---------------------------------------------------------------------------
#ifndef GPDXL_CDXLLogicalReturning_H
#define GPDXL_CDXLLogicalReturning_H

#include "gpos/base.h"

#include "naucrates/dxl/operators/CDXLLogical.h"
#include "naucrates/dxl/operators/CDXLNode.h"

namespace gpdxl
{

//---------------------------------------------------------------------------
//	@class:
//		CDXLLogicalReturning
//
//	@doc:
//		Class for representing DXL Logical returning list operators
//
//---------------------------------------------------------------------------
class CDXLLogicalReturning : public CDXLLogical
{
private:
	// private copy ctor
	CDXLLogicalReturning(CDXLLogicalReturning &);

public:
	// ctor/dtor
	CDXLLogicalReturning(CMemoryPool *mp);

	virtual ~CDXLLogicalReturning();

	// accessors
	Edxlopid GetDXLOperator() const;

	const CWStringConst *GetOpNameStr() const;

	// serialize operator in DXL format
	virtual void SerializeToDXL(CXMLSerializer *xml_serializer,
								const CDXLNode *node) const;

	// conversion function
	static CDXLLogicalReturning *
	Cast(CDXLOperator *dxl_op)
	{
		GPOS_ASSERT(NULL != dxl_op);
		GPOS_ASSERT(EdxlopLogicalReturning == dxl_op->GetDXLOperator());

		return dynamic_cast<CDXLLogicalReturning *>(dxl_op);
	}

	// checks whether the operator has valid structure, i.e. number and
	// types of child nodes
	void AssertValid(const CDXLNode *, BOOL validate_children) const;
};
}  // namespace gpdxl
#endif	// !GPDXL_CDXLLogicalReturning_H

// EOF
