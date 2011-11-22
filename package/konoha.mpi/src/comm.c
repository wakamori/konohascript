#ifndef _KNH_ON_T2K
#include "../konoha_mpi.h"
#endif

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.getRank();
KMETHOD MPIComm_getRank(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(MPIC_RANK((knh_MPIComm_t*)sfp[0].o));
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.getSize();
KMETHOD MPIComm_getSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(MPIC_SIZE((knh_MPIComm_t*)sfp[0].o));
}

/* ------------------------------------------------------------------------ */
//## method String MPIComm.getProcessorName();
KMETHOD MPIComm_getProcessorName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURN_(new_String(ctx, (const char*)(((knh_MPIComm_t*)sfp[0].o)->proc_name)));
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.barrier();
KMETHOD MPIComm_barrier(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(MPI_Barrier(MPIC_COMM((knh_MPIComm_t*)sfp[0].o)));
}

/* ------------------------------------------------------------------------ */
//## method MPIComm MPIComm.create(IArray ranks);

KMETHOD MPIComm_create(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPI_Group base, newg;
	MPIC(comm, sfp[0].o);
	knh_Array_t *ids = sfp[1].a;
	MPIC(newc, new_O(MPIComm, O_cid(sfp[0].o)));
	int len = knh_Array_size(ids);
	if (len > 0) {
		int i, ranks[len];
		for (i = 0; i < len; i++) {
			knh_int_t r = (knh_int_t)knh_Array_n(ids, i);
			ranks[i] = (int)r;
		}
		MPI_Comm_group(MPIC_COMM(comm), &base);
		MPI_Group_incl(base, len, ranks, &newg);
		MPI_Comm_create(MPIC_COMM(comm), newg, &MPIC_COMM(newc));
		MPI_Comm_rank(MPIC_COMM(newc), &MPIC_RANK(newc));
		MPI_Comm_size(MPIC_COMM(newc), &MPIC_SIZE(newc));
		MPIC_PROC(newc) = strdup(MPIC_PROC(comm)); // to be free
	}
	RETURN_(newc);
}
