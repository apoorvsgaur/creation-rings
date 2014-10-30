function varargout = otherfilesGUI_sec008_team24(varargin)
% OTHERFILESGUI_SEC008_TEAM24 MATLAB code for otherfilesGUI_sec008_team24.fig
%      OTHERFILESGUI_SEC008_TEAM24, by itself, creates a new OTHERFILESGUI_SEC008_TEAM24 or raises the existing
%      singleton*.
%
%      H = OTHERFILESGUI_SEC008_TEAM24 returns the handle to a new OTHERFILESGUI_SEC008_TEAM24 or the handle to
%      the existing singleton*.
%
%      OTHERFILESGUI_SEC008_TEAM24('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in OTHERFILESGUI_SEC008_TEAM24.M with the given input arguments.
%
%      OTHERFILESGUI_SEC008_TEAM24('Property','Value',...) creates a new OTHERFILESGUI_SEC008_TEAM24 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before otherfilesGUI_sec008_team24_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to otherfilesGUI_sec008_team24_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help otherfilesGUI_sec008_team24

% Last Modified by GUIDE v2.5 11-Apr-2013 22:38:56

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @otherfilesGUI_sec008_team24_OpeningFcn, ...
                   'gui_OutputFcn',  @otherfilesGUI_sec008_team24_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before otherfilesGUI_sec008_team24 is made visible.
function otherfilesGUI_sec008_team24_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to otherfilesGUI_sec008_team24 (see VARARGIN)

% Choose default command line output for otherfilesGUI_sec008_team24
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes otherfilesGUI_sec008_team24 wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = otherfilesGUI_sec008_team24_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in toLast.
function toLast_Callback(hObject, eventdata, handles)
% hObject    handle to toLast (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in nexSlide.
function nexSlide_Callback(hObject, eventdata, handles)
% hObject    handle to nexSlide (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in ovSlide.
function ovSlide_Callback(hObject, eventdata, handles)
% hObject    handle to ovSlide (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in homeSlide.
function homeSlide_Callback(hObject, eventdata, handles)
% hObject    handle to homeSlide (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in toHome.
function toHome_Callback(hObject, eventdata, handles)
% hObject    handle to toHome (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in toOv.
function toOv_Callback(hObject, eventdata, handles)
% hObject    handle to toOv (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in toNext.
function toNext_Callback(hObject, eventdata, handles)
% hObject    handle to toNext (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes during object creation, after setting all properties.
function axes1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to axes1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: place code in OpeningFcn to populate axes1
axes(hObject);
imshow('Picture_Nano.png');
