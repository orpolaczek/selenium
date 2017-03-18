// Licensed to the Software Freedom Conservancy (SFC) under one
// or more contributor license agreements. See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership. The SFC licenses this file
// to you under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "GoForwardCommandHandler.h"
#include "errorcodes.h"
#include "../Browser.h"
#include "../IECommandExecutor.h"

namespace webdriver {

GoForwardCommandHandler::GoForwardCommandHandler(void) {
}

GoForwardCommandHandler::~GoForwardCommandHandler(void) {
}

void GoForwardCommandHandler::ExecuteInternal(
    const IECommandExecutor& executor,
    const ParametersMap& command_parameters,
    Response* response) {
  BrowserHandle browser_wrapper;
  int status_code = executor.GetCurrentBrowser(&browser_wrapper);
  if (status_code != WD_SUCCESS) {
    response->SetErrorResponse(status_code, "Unable to get browser");
    return;
  }
  status_code = browser_wrapper->NavigateForward();
  response->SetSuccessResponse(Json::Value::null);
}

} // namespace webdriver
