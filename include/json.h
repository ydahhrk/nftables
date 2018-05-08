#ifndef NFTABLES_JSON_H
#define NFTABLES_JSON_H

struct chain;
struct cmd;
struct expr;
struct netlink_ctx;
struct rule;
struct set;
struct stmt;
struct symbol_table;
struct table;

#ifdef HAVE_LIBJANSSON

#include <jansson.h>

json_t *binop_expr_json(const struct expr *expr, struct output_ctx *octx);
json_t *relational_expr_json(const struct expr *expr, struct output_ctx *octx);
json_t *range_expr_json(const struct expr *expr, struct output_ctx *octx);
json_t *meta_expr_json(const struct expr *expr, struct output_ctx *octx);
json_t *payload_expr_json(const struct expr *expr, struct output_ctx *octx);
json_t *ct_expr_json(const struct expr *expr, struct output_ctx *octx);
json_t *concat_expr_json(const struct expr *expr, struct output_ctx *octx);
json_t *set_expr_json(const struct expr *expr, struct output_ctx *octx);
json_t *set_ref_expr_json(const struct expr *expr, struct output_ctx *octx);
json_t *set_elem_expr_json(const struct expr *expr, struct output_ctx *octx);
json_t *prefix_expr_json(const struct expr *expr, struct output_ctx *octx);
json_t *list_expr_json(const struct expr *expr, struct output_ctx *octx);
json_t *unary_expr_json(const struct expr *expr, struct output_ctx *octx);
json_t *mapping_expr_json(const struct expr *expr, struct output_ctx *octx);
json_t *map_expr_json(const struct expr *expr, struct output_ctx *octx);
json_t *exthdr_expr_json(const struct expr *expr, struct output_ctx *octx);
json_t *verdict_expr_json(const struct expr *expr, struct output_ctx *octx);
json_t *rt_expr_json(const struct expr *expr, struct output_ctx *octx);
json_t *numgen_expr_json(const struct expr *expr, struct output_ctx *octx);
json_t *hash_expr_json(const struct expr *expr, struct output_ctx *octx);
json_t *fib_expr_json(const struct expr *expr, struct output_ctx *octx);
json_t *constant_expr_json(const struct expr *expr, struct output_ctx *octx);

json_t *integer_type_json(const struct expr *expr, struct output_ctx *octx);
json_t *string_type_json(const struct expr *expr, struct output_ctx *octx);
json_t *boolean_type_json(const struct expr *expr, struct output_ctx *octx);
json_t *inet_protocol_type_json(const struct expr *expr,
				struct output_ctx *octx);
json_t *inet_service_type_json(const struct expr *expr,
			       struct output_ctx *octx);
json_t *mark_type_json(const struct expr *expr, struct output_ctx *octx);
json_t *devgroup_type_json(const struct expr *expr, struct output_ctx *octx);
json_t *ct_label_type_json(const struct expr *expr, struct output_ctx *octx);
json_t *time_type_json(const struct expr *expr, struct output_ctx *octx);
json_t *uid_type_json(const struct expr *expr, struct output_ctx *octx);
json_t *gid_type_json(const struct expr *expr, struct output_ctx *octx);

json_t *expr_stmt_json(const struct stmt *stmt, struct output_ctx *octx);
json_t *payload_stmt_json(const struct stmt *stmt, struct output_ctx *octx);
json_t *exthdr_stmt_json(const struct stmt *stmt, struct output_ctx *octx);
json_t *quota_stmt_json(const struct stmt *stmt, struct output_ctx *octx);
json_t *ct_stmt_json(const struct stmt *stmt, struct output_ctx *octx);
json_t *limit_stmt_json(const struct stmt *stmt, struct output_ctx *octx);
json_t *fwd_stmt_json(const struct stmt *stmt, struct output_ctx *octx);
json_t *notrack_stmt_json(const struct stmt *stmt, struct output_ctx *octx);
json_t *dup_stmt_json(const struct stmt *stmt, struct output_ctx *octx);
json_t *meta_stmt_json(const struct stmt *stmt, struct output_ctx *octx);
json_t *nat_stmt_json(const struct stmt *stmt, struct output_ctx *octx);
json_t *reject_stmt_json(const struct stmt *stmt, struct output_ctx *octx);
json_t *counter_stmt_json(const struct stmt *stmt, struct output_ctx *octx);
json_t *set_stmt_json(const struct stmt *stmt, struct output_ctx *octx);
json_t *log_stmt_json(const struct stmt *stmt, struct output_ctx *octx);
json_t *objref_stmt_json(const struct stmt *stmt, struct output_ctx *octx);
json_t *meter_stmt_json(const struct stmt *stmt, struct output_ctx *octx);
json_t *queue_stmt_json(const struct stmt *stmt, struct output_ctx *octx);
json_t *verdict_stmt_json(const struct stmt *stmt, struct output_ctx *octx);

int do_command_list_json(struct netlink_ctx *ctx, struct cmd *cmd);

#else /* ! HAVE_LIBJANSSON */

typedef void json_t;

#define JSON_PRINT_STUB(name, arg1_t, arg2_t) \
static inline json_t *name##_json(arg1_t arg1, arg2_t arg2) { return NULL; }

#define EXPR_PRINT_STUB(name) \
	JSON_PRINT_STUB(name, const struct expr *, struct output_ctx *)
#define STMT_PRINT_STUB(name) \
	JSON_PRINT_STUB(name##_stmt, const struct stmt *, struct output_ctx *)

EXPR_PRINT_STUB(binop_expr)
EXPR_PRINT_STUB(relational_expr)
EXPR_PRINT_STUB(range_expr)
EXPR_PRINT_STUB(meta_expr)
EXPR_PRINT_STUB(payload_expr)
EXPR_PRINT_STUB(ct_expr)
EXPR_PRINT_STUB(concat_expr)
EXPR_PRINT_STUB(set_expr)
EXPR_PRINT_STUB(set_ref_expr)
EXPR_PRINT_STUB(set_elem_expr)
EXPR_PRINT_STUB(prefix_expr)
EXPR_PRINT_STUB(list_expr)
EXPR_PRINT_STUB(unary_expr)
EXPR_PRINT_STUB(mapping_expr)
EXPR_PRINT_STUB(map_expr)
EXPR_PRINT_STUB(exthdr_expr)
EXPR_PRINT_STUB(verdict_expr)
EXPR_PRINT_STUB(rt_expr)
EXPR_PRINT_STUB(numgen_expr)
EXPR_PRINT_STUB(hash_expr)
EXPR_PRINT_STUB(fib_expr)
EXPR_PRINT_STUB(constant_expr)

EXPR_PRINT_STUB(integer_type)
EXPR_PRINT_STUB(string_type)
EXPR_PRINT_STUB(boolean_type)
EXPR_PRINT_STUB(inet_protocol_type)
EXPR_PRINT_STUB(inet_service_type)
EXPR_PRINT_STUB(mark_type)
EXPR_PRINT_STUB(devgroup_type)
EXPR_PRINT_STUB(ct_label_type)
EXPR_PRINT_STUB(time_type)
EXPR_PRINT_STUB(uid_type)
EXPR_PRINT_STUB(gid_type)

STMT_PRINT_STUB(expr)
STMT_PRINT_STUB(payload)
STMT_PRINT_STUB(exthdr)
STMT_PRINT_STUB(quota)
STMT_PRINT_STUB(ct)
STMT_PRINT_STUB(limit)
STMT_PRINT_STUB(fwd)
STMT_PRINT_STUB(notrack)
STMT_PRINT_STUB(dup)
STMT_PRINT_STUB(meta)
STMT_PRINT_STUB(nat)
STMT_PRINT_STUB(reject)
STMT_PRINT_STUB(counter)
STMT_PRINT_STUB(set)
STMT_PRINT_STUB(log)
STMT_PRINT_STUB(objref)
STMT_PRINT_STUB(meter)
STMT_PRINT_STUB(queue)
STMT_PRINT_STUB(verdict)

#undef STMT_PRINT_STUB
#undef EXPR_PRINT_STUB
#undef JSON_PRINT_STUB

static inline json_t *symbolic_constant_json(const struct symbol_table *tbl,
					     const struct expr *expr)
{
	return NULL;
}

static inline int do_command_list_json(struct netlink_ctx *ctx, struct cmd *cmd)
{
	return -1;
}

#endif /* HAVE_LIBJANSSON */

#endif /* NFTABLES_JSON_H */