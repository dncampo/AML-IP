# Copyright 2022 Proyectos y Sistemas de Mantenimiento SL (eProsima).
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
"""AML-IP AmlipIdDataType data type API specification."""


from amlip_swig import AmlipIdDataType as cpp_AmlipIdDataType


class AmlipIdDataType(cpp_AmlipIdDataType):
    """
    TODO
    """

    def __init__(self, name: str):
        super().__init__(name)


    def get_name(self) -> str:
        return cpp_AmlipIdDataType.name()


    def is_defined(self) -> bool:
        return cpp_AmlipIdDataType.is_defined(self)

    # TODO check if this is needed or it is taken from parent
    # def __str__(self) -> str:
    #     return super().__str__()
