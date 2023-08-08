// SPDX-License-Identifier: MIT
#include <cmocka_extensions/cmocka_extensions.h>
#include <stdint.h>

#include "safu/mock_safu.h"
#include "samconfLookupBackend_utest.h"

void samconfTestSamconfLookupBackendSuccess(UNUSED void **state) {
    samconfConfigStatusE_t status;
    samconfConfigBackend_t *backendPtr;
    samconfConfigBackend_t backend = {
        .ops = &samconfDefaultOps,
    };
    const char *location = "config.json";

    TEST("samconfTestSamconfLookupBackend");
    SHOULD("%s", "successfully lookup a configuration backend");

    MOCK_FUNC_ALWAYS(samconfGetBackendOps);
    expect_value_count(samconfGetBackendOps, idx, 0, -1);
    will_return_count(samconfGetBackendOps, &samconfDefaultOps, -1);

    MOCK_FUNC_AFTER_CALL(samconfConfigBackendNew, 0);
    expect_value(samconfConfigBackendNew, backend, &backendPtr);
    expect_value(samconfConfigBackendNew, ops, &samconfDefaultOps);
    will_set_parameter(samconfConfigBackendNew, backend, &backend);
    will_return(samconfConfigBackendNew, SAMCONF_CONFIG_OK);

    status = samconfLookupBackend(location, &backendPtr);

    MOCK_FUNC_DISABLE(samconfGetBackendOps);

    assert_int_equal(status, SAMCONF_CONFIG_OK);
}
