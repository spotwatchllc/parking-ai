# /*---------------------------------------------------------------------------------------------
#  * Copyright (c) 2023 STMicroelectronics. All rights reserved.
#  * This software is licensed under terms that can be found in the LICENSE
#  * file in the root directory of this software component.
#  * If no LICENSE file comes with this software, it is provided AS-IS.
#  *--------------------------------------------------------------------------------------------*/


import os
from typing import Union
import urllib.parse

USE_TEST_ROUTES_EV = 'USE_TEST_ROUTES'


class BackendEndpoints:
    BASE_URL = 'https://stm32ai-cs.st.com/'
    USER_SERVICE_URL = 'https://stm32ai-cs.st.com/api/user_service'
    FILE_SERVICE_URL = 'https://stm32ai-cs.st.com/api/file'
    GENERATE_NBG_SERVICE_URL = 'https://stm32ai-cs.st.com/api/generate_nbg'
    BENCHMARK_SERVICE_URL = 'https://stm32ai-cs.st.com/api/benchmark'
    VERSIONS_URL = 'https://stm32ai-cs.st.com/assets/versions.json'
    SSO_URL = 'https://sso.st.com'
    CLIENTID = 'oidc_prod_client_app_stm32ai'
    CALLBACK_URL = 'https://stm32ai-cs.st.com/callback'
class BackendTestEndpoints:
    BASE_URL = 'https://stm32ai-cs-qa.st.com/'
    USER_SERVICE_URL = 'https://stm32ai-cs-qa.st.com/api/user_service'
    FILE_SERVICE_URL = 'https://stm32ai-cs-qa.st.com/api/file'
    GENERATE_NBG_SERVICE_URL = 'https://stm32ai-cs-qa.st.com/api/generate_nbg'
    BENCHMARK_SERVICE_URL = 'https://stm32ai-cs-qa.st.com/api/benchmark'
    VERSIONS_URL = 'https://stm32ai-cs-qa.st.com/assets/versions.json'
    SSO_URL = 'https://qa-sso.st.com'
    CLIENTID = 'oidc_pre_prod_client_app'
    CALLBACK_URL = 'https://stm32ai-cs-qa.st.com/callback'


class BackendEvName:
    BASE_URL = "BASE_URL"
    STM32AI_SERVICE_URL = "STM32AI_SERVICE_URL"
    LOGIN_SERVICE_URL = "LOGIN_SERVICE_URL"
    USER_SERVICE_URL = "USER_SERVICE_URL"
    FILE_SERVICE_URL = "FILE_SERVICE_URL"
    GENERATE_NBG_SERVICE_URL = "GENERATE_NBG_SERVICE_URL"
    BENCHMARK_SERVICE_URL = "BENCHMARK_SERVICE_URL"
    VERSIONS_URL = 'VERSIONS_URL'
    SSO_URL = 'SSO_URL'
    CLIENTID = 'CLIENTID'
    CALLBACK_URL = 'CALLBACK_URL'

# ######## User service related functions ########


def get_user_service_ep():
    """
    Main route to get user related data
    """
    if os.environ.get(BackendEvName.USER_SERVICE_URL):
        return os.environ.get(BackendEvName.USER_SERVICE_URL)

    if os.environ.get(USE_TEST_ROUTES_EV):
        return BackendTestEndpoints.USER_SERVICE_URL
    else:
        return BackendEndpoints.USER_SERVICE_URL


# ######## Login service related functions ########
    
def get_callback_url_ep():
    if os.environ.get(BackendEvName.CALLBACK_URL):
        return os.environ.get(BackendEvName.CALLBACK_URL)

    if os.environ.get(USE_TEST_ROUTES_EV):
        return BackendTestEndpoints.CALLBACK_URL
    else:
        return BackendEndpoints.CALLBACK_URL
        
def get_client_id_ep():
    if os.environ.get(BackendEvName.CLIENTID):
        return os.environ.get(BackendEvName.CLIENTID)

    if os.environ.get(USE_TEST_ROUTES_EV):
        return BackendTestEndpoints.CLIENTID
    else:
        return BackendEndpoints.CLIENTID

def get_sso_url_ep():
    if os.environ.get(BackendEvName.SSO_URL):
        return os.environ.get(BackendEvName.SSO_URL)

    if os.environ.get(USE_TEST_ROUTES_EV):
        return BackendTestEndpoints.SSO_URL
    else:
        return BackendEndpoints.SSO_URL

def get_login_service_ep():
    """
    Main route to access login features
    """

    if os.environ.get(BackendEvName.USER_SERVICE_URL):
        return os.environ.get(BackendEvName.USER_SERVICE_URL)

    if os.environ.get(USE_TEST_ROUTES_EV):
        return BackendTestEndpoints.USER_SERVICE_URL
    else:
        return BackendEndpoints.USER_SERVICE_URL


def get_login_authenticate_ep():
    """
    Route on which user check authentication status (GET)
    and authenticate (POST)
    """
    return get_login_service_ep() + '/authenticate'


# ######## stm32ai related functions ########


def get_stm32ai_service_ep(version: Union[str, None]):
    """
    Main route to access stm32ai service
    """
    if os.environ.get(BackendEvName.STM32AI_SERVICE_URL):
        return os.environ.get(BackendEvName.STM32AI_SERVICE_URL)

    base_url = BackendTestEndpoints.BASE_URL if os.environ.get(USE_TEST_ROUTES_EV, False) else BackendEndpoints.BASE_URL
    endpoint = f'/api/{version}/stm32ai/' if version else '/api/stm32ai/'
    return urllib.parse.urljoin(base=base_url, url=endpoint)


def get_stm32ai_analyze_ep(version: Union[str, None]):
    return get_stm32ai_service_ep(version) + '/analyze'


def get_stm32ai_generate_ep(version: Union[str, None]):
    return get_stm32ai_service_ep(version) + '/generate'


def get_stm32ai_validate_ep(version: Union[str, None]):
    return get_stm32ai_service_ep(version) + '/validate'


def get_stm32ai_run(version: Union[str, None], runtime_id: str):
    return get_stm32ai_service_ep(version)+f'/run/{runtime_id}'


def get_file_service_ep():
    """
    Main route to access the file service
    """
    if os.environ.get(BackendEvName.FILE_SERVICE_URL):
        return os.environ.get(BackendEvName.FILE_SERVICE_URL)

    if os.environ.get(USE_TEST_ROUTES_EV):
        return BackendTestEndpoints.FILE_SERVICE_URL
    else:
        return BackendEndpoints.FILE_SERVICE_URL

def get_generate_nbg_service_ep():
    """
    Main route to access the generate_nbg service
    """
    if os.environ.get(BackendEvName.GENERATE_NBG_SERVICE_URL):
        return os.environ.get(BackendEvName.GENERATE_NBG_SERVICE_URL)

    if os.environ.get(USE_TEST_ROUTES_EV):
        return BackendTestEndpoints.GENERATE_NBG_SERVICE_URL
    else:
        return BackendEndpoints.GENERATE_NBG_SERVICE_URL


def get_benchmark_service_ep():
    """
    Main route to access benchmark service
    """
    if os.environ.get(BackendEvName.BENCHMARK_SERVICE_URL):
        return os.environ.get(BackendEvName.BENCHMARK_SERVICE_URL)

    if os.environ.get(USE_TEST_ROUTES_EV):
        return BackendTestEndpoints.BENCHMARK_SERVICE_URL
    else:
        return BackendEndpoints.BENCHMARK_SERVICE_URL


def get_benchmark_boards_ep():
    return f'{get_benchmark_service_ep()}/boards'


def get_benchmark_openapi_ep():
    return f'{get_benchmark_service_ep()}/api'

def get_supported_versions_ep():
    """
    Get supported versions on Dev. Cloud
    """
    if os.environ.get(BackendEvName.VERSIONS_URL):
        return os.environ.get(BackendEvName.VERSIONS_URL)

    if os.environ.get(USE_TEST_ROUTES_EV):
        return BackendTestEndpoints.VERSIONS_URL
    else:
        return BackendEndpoints.VERSIONS_URL