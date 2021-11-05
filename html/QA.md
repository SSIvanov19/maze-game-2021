# QA Documentation
# QA Documentation
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque id sollicitudin mi, ac ultricies est. Donec tristique elit metus, sit amet scelerisque tellus suscipit non. Nunc ornare velit in mi dictum, eget viverra elit accumsan. Sed congue condimentum erat ut gravida. Donec non posuere dolor, quis commodo erat. Morbi sit amet sem sed urna ullamcorper viverra vitae non turpis. Suspendisse ut faucibus turpis. Aliquam suscipit orci sodales interdum egestas. Quisque pulvinar odio in luctus ullamcorper. Cras nulla nunc, sodales suscipit consectetur non, facilisis et lectus. Donec nec ornare orci. Duis pellentesque porttitor leo at condimentum.

Aenean tincidunt vitae erat sit amet fermentum. Duis ac lacinia risus. Aenean felis urna, elementum eget fringilla vitae, fermentum ac enim. Etiam sit amet dui enim. Ut in pellentesque sem, nec sodales nisi. Donec varius pharetra consectetur. Maecenas at consectetur tortor. Morbi convallis pulvinar erat ut finibus. Interdum et malesuada fames ac ante ipsum primis in faucibus. Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus.

# Test Cases
## Account System
### Test Case 1
| | | | | | | | |
|-|-|-|-|-|-|-|-|
| | |ID|TS1_001|Created by|Kostadin Taligadzhiev| | |
| | |Name|Register firefighter account| | | | |
| | |Description|Testing the registration form for firefighters|Created on|21/04/2021| | |
| | | | | | | | |
| | |#|Description|Test Data|Expectations|Actual Result|Status|
| | |1|When I press the register button I should see a success or error message.|E-mail: test@burgas.com|User created successfully!|User created successfully! And then disappears very quickly.|FAILED|
| | | | |Fname: Ime1  Lname: Fam1| | | |
| | | | |Password: 123456789| | | |
### Test Case 2
| | | | | | | | |
|-|-|-|-|-|-|-|-|
| | |ID|TS1_002|Created by|Kostadin Taligadzhiev| | |
| | |Name|Register firefighter account| | | | |
| | |Description|Testing the registration form for firefighters|Created on|22/04/2021| | |
| | | | | | | | |
| | |#|Description|Test Data|Expectations|Actual Result|Status|
| | |1|When I press the register button I should see a success or error message.|E-mail: test@burgas.com|User created successfully!|User created successfully!|PASSED|
| | | | |Fname: Ime1  Lname: Fam1| | | |
| | | | |Password: 123456789| | | |
### Test Case 3
| | | | | | | | |
|-|-|-|-|-|-|-|-|
| | |ID|TS1_003|Created by|Kostadin Taligadzhiev| | |
| | |Name|Register firefighter account| | | | |
| | |Description|Testing the registration form for firefighters|Created on|21/04/2021| | |
| | | | | | | | |
| | |#|Description|Test Data|Expectations|Actual Result|Status|
| | |1|When I press the register button I should see an error message.|E-mail: имейл|The email is invalid!|User created successfully!|FAILED|
| | | | |Fname: Ime1  Lname: Fam1| | | |
| | | | |Password: 123456789| | | |

### Test Case 4
| | | | | | | | |
|-|-|-|-|-|-|-|-|
| | |ID|TS1_004|Created by|Kostadin Taligadzhiev| | |
| | |Name|Register firefighter account| | | | |
| | |Description|Testing the registration form for firefighters|Created on|22/04/2021| | |
| | | | | | | | |
| | |#|Description|Test Data|Expectations|Actual Result|Status|
| | |1|When I press the register button I should see an error message.|E-mail: имейл|The email is invalid!|The email is invalid!|PASSED|
| | | | |Fname: Ime1  Lname: Fam1| | | |
| | | | |Password: 123456789| | | |

### Test Case 5
| | | | | | | | |
|-|-|-|-|-|-|-|-|
| | |ID|TS1_005|Created by|Kostadin Taligadzhiev| | |
| | |Name|Register firefighter account| | | | |
| | |Description|Testing signal form|Created on|21/04/2021| | |
| | | | | | | | |
| | |#|Description|Test Data|Expectations|Actual Result|Status|
| | |1|After pressing the button it should send the signal.|E-mail: test@burgas.com|Signal submit!|Signal submit!|PASSED|
| | | | |Fname: Ime1  Lname: Fam1| | | |
| | | | |Password: 123456789| | | |

## Signal system
### Test Case 1
| | | | | | | | |
|-|-|-|-|-|-|-|-|
| | |ID|TS1_001|Created by|Kostadin Taligadzhiev| | |
| | |Name|Register firefighter account| | | | |
| | |Description|Testing the registration form for firefighters|Created on|21/04/2021| | |
| | | | | | | | |
| | |#|Description|Test Data|Expectations|Actual Result|Status|
| | |1|When I press the register button I should see a success or error message.|E-mail: test@burgas.com|User created successfully!|User created successfully! And then disappears very quickly.|FAILED|
| | | | |Fname: Ime1  Lname: Fam1| | | |
| | | | |Password: 123456789| | | |
### Test Case 2
| | | | | | | | |
|-|-|-|-|-|-|-|-|
| | |ID|TS1_002|Created by|Kostadin Taligadzhiev| | |
| | |Name|Register firefighter account| | | | |
| | |Description|Testing the registration form for firefighters|Created on|22/04/2021| | |
| | | | | | | | |
| | |#|Description|Test Data|Expectations|Actual Result|Status|
| | |1|When I press the register button I should see a success or error message.|E-mail: test@burgas.com|User created successfully!|User created successfully!|PASSED|
| | | | |Fname: Ime1  Lname: Fam1| | | |
| | | | |Password: 123456789| | | |
### Test Case 3
| | | | | | | | |
|-|-|-|-|-|-|-|-|
| | |ID|TS1_003|Created by|Kostadin Taligadzhiev| | |
| | |Name|Register firefighter account| | | | |
| | |Description|Testing the registration form for firefighters|Created on|21/04/2021| | |
| | | | | | | | |
| | |#|Description|Test Data|Expectations|Actual Result|Status|
| | |1|When I press the register button I should see an error message.|E-mail: имейл|The email is invalid!|User created successfully!|FAILED|
| | | | |Fname: Ime1  Lname: Fam1| | | |
| | | | |Password: 123456789| | | |

### Test Case 4
| | | | | | | | |
|-|-|-|-|-|-|-|-|
| | |ID|TS1_004|Created by|Kostadin Taligadzhiev| | |
| | |Name|Register firefighter account| | | | |
| | |Description|Testing the registration form for firefighters|Created on|22/04/2021| | |
| | | | | | | | |
| | |#|Description|Test Data|Expectations|Actual Result|Status|
| | |1|When I press the register button I should see an error message.|E-mail: имейл|The email is invalid!|The email is invalid!|PASSED|
| | | | |Fname: Ime1  Lname: Fam1| | | |
| | | | |Password: 123456789| | | |

### Test Case 5
| | | | | | | | |
|-|-|-|-|-|-|-|-|
| | |ID|TS1_005|Created by|Kostadin Taligadzhiev| | |
| | |Name|Register firefighter account| | | | |
| | |Description|Testing signal form|Created on|21/04/2021| | |
| | | | | | | | |
| | |#|Description|Test Data|Expectations|Actual Result|Status|
| | |1|After pressing the button it should send the signal.|E-mail: test@burgas.com|Signal submit!|Signal submit!|PASSED|
| | | | |Fname: Ime1  Lname: Fam1| | | |
| | | | |Password: 123456789| | | |