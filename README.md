# bootcamp-unreal

This repository contains all the source code from the lessons in Unreal BootCamp. Each lesson that contains source code has a corresponding branch. More details are in the Notes section below.

The Unreal BootCamp can be found at the link below:

https://bootcamp.braincloudservers.com/?mto-course=braincloud-bootcamp-unreal

If you haven't signed up or you want to log into the brainCloud portal, you can do that here:

https://portal.braincloudservers.com/


## Installation Guide

```bash
git clone https://github.com/getbraincloud/bootcamp-unreal.git
cd bootcamp-unreal
```

## Notes

The Unreal BootCamp series was designed with an already 'completed' example game, that simply needed to have brainCloud integrated into it.

There are 35 lessons in the Unreal BootCamp, however some of the lessons don't have source code. In fact, only 24 of the 35 lessons have source code. Each lesson has a seperate branch in this repository. Each branch contains the example Unreal project source code in its final state for the corresponding lesson. 

Since Unreal 5 project are not backwards compatible with Unreal 4, the Unreal BootCamp lessons have separate repositories for Unreal 4.27 and 5.1 projects. Each lesson's branch is post-fixed with **_5.1** or **_4.27**.

For example: 
  - The branch for Lesson 3's UE4 source code is called: **Lesson-3_4.27**
  - The branch for Lesson 3's UE5 source code is called: **Lesson-3_5.1**

There is also a branch for the initial Unreal example project, this branch contains the starter game code without the brainCloud Unreal client. If you plan to follow along and code with the BootCamp series, its recommended that you clone this repository and checkout either the **Initial-Project_4.27** branch or the **Initial-Project_5.1** branch.

